#include "mainwindow.h"
#include "const.h"


MainWindow* MainWindow::MainWindowInstance = NULL;

MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
// 	this->setWindowTitle("车站报警统计界面");
	MainWindowInstance = this;
	this->setWindowFlags(Qt::WindowMinimizeButtonHint);
	m_dataList = getGlobalModelInstance()->getStationDataArr();
	ui.setupUi(this); 
	loadStationDataArr();
}

void MainWindow::loadStationDataArr()
{
	int iwidth = this->width();
	int iheight = this->height();

	disconnect(ui.tableWidget,SIGNAL(cellChanged(int,int)),this,SLOT(updateStationData(int,int)));
	
	for (int i = 0; i< ui.tableWidget->rowCount(); i++ )
	{
		ui.tableWidget->removeRow(i);
	}

	ui.tableWidget->setRowCount(4);
	ui.tableWidget->setColumnCount(m_dataList.size()+1); 

	ui.tableWidget->verticalHeader()->setVisible(false);
	ui.tableWidget->horizontalHeader()->setVisible(false);
	ui.tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);

	ui.tableWidget->setItem(0,0,new QTableWidgetItem("报警级别"));
	ui.tableWidget->setItem(1,0,new QTableWidgetItem("一级警报"));
	ui.tableWidget->setItem(2,0,new QTableWidgetItem("二级警报"));
	ui.tableWidget->setItem(3,0,new QTableWidgetItem("三级警报"));
	ui.tableWidget->setRowHeight(0, 20);
	ui.tableWidget->setRowHeight(1, 20);
	ui.tableWidget->setRowHeight(2, 20);
	ui.tableWidget->setRowHeight(3, 20);

	int istartRectX = 0; 

	for (int i=0; i<m_dataList.size(); i++)
	{
		StationData data = m_dataList[i];
		ui.tableWidget->setColumnWidth(i, 80);

		ui.tableWidget->setItem(0,i+1,new QTableWidgetItem(data.strStationName));
		ui.tableWidget->setItem(1,i+1,new QTableWidgetItem(QString::number(data.iWarning1No)) );
		ui.tableWidget->setItem(2,i+1,new QTableWidgetItem(QString::number(data.iWarning2No)) );
		ui.tableWidget->setItem(3,i+1,new QTableWidgetItem(QString::number(data.iWarning3No)) );
	}

	connect(ui.tableWidget,SIGNAL(cellChanged(int,int)),this,SLOT(updateStationData(int,int)));

}

void MainWindow::updateStationData(int row,int column){

	QTableWidgetItem * item1 = new QTableWidgetItem;
	item1 = ui.tableWidget->item(row,column);
	int modifyValue = item1->text().toInt();
	getGlobalControllerInstance()->modifyStationData(StationDataType(row-1), column-1, modifyValue);
}


MainWindow::~MainWindow()
{
	m_dataList.clear();
}

//刷新函数
void MainWindow::refreshAllStationData(){
	m_dataList.clear();
	m_dataList = getGlobalModelInstance()->getStationDataArr();
	loadStationDataArr();
	//界面重新绘制
	ui.tableWidget->update();
	ui.pSGrapgWidget1->update();
	ui.pSGrapgWidget2->update();

// 	this->update();
}

void MainWindow::paintEvent(QPaintEvent *pQpaint )
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
	int iwidth = this->width();
	int iheight = this->height();
	ui.scrollArea->setMaximumSize(iwidth-20,g_Graph1RectHeight+30);

//	ui.pSGrapgWidget1->setMaximumSize(iwidth-+50,g_Graph1RectHeight+30);

	int graphWidget1Width = 40 + m_dataList.size()*90+80;

	if (graphWidget1Width< iwidth-20)
	{
		graphWidget1Width = iwidth-20;
	}

	ui.pSGrapgWidget1->setFixedSize(graphWidget1Width, g_Graph1RectHeight);

//  	ui.centralWidget->setGeometry(QRect(5, 5, iwidth-20, 600));
//  	ui.tableWidget->setGeometry(5,5, iwidth-20, 90);
// 	ui.tableWidget->setGeometry(5,5, iwidth-20, 90);
// 	ui.tableWidget->setGeometry(5,5, iwidth-20, 90);
}

