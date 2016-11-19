#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "ui_mainwindow.h"
#include <QtGui/QMainWindow>
#include "ui_MainWindow.h"
#include <QPaintEvent>
#include "QTableWidget"
#include "QVBoxLayout"
#include "QRadioButton"
#include "Controller.h"
#include "SGraphWidget1.h"

//车站分析界面
class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	static MainWindow* MainWindowInstance;

public:
	MainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MainWindow();

	//刷新所有车站数据
	void refreshAllStationData();

protected:
	//界面绘制
	virtual void paintEvent(QPaintEvent* event);

private:
	void loadStationDataArr();

private slots:
	void updateStationData(int irow, int icolum);

private:
	Ui::MainWindowClass ui;
	vStationData m_dataList;
};

#endif // MainWindow_H
