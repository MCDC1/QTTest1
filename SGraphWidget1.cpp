#include "const.h"
#include "SGraphWidget1.h"
#include "Model.h"

SGrapgWidget1::SGrapgWidget1(QWidget *parent)
	: QWidget(parent)
{
	m_dataList = getGlobalModelInstance()->getStationDataArr();
}

SGrapgWidget1::SGrapgWidget1()
{
}

void SGrapgWidget1::update(){
	QWidget::update();
	m_dataList = getGlobalModelInstance()->getStationDataArr();
}


void SGrapgWidget1::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	//���ƻ�ͼ����
	drawAllGraphRect(&painter);

	int istartRectX = 40;
	int istartRectY = g_Graph1RectHeight-20;

	int iAllWarningNo = getGlobalModelInstance()->getAllWarningNo();

	for (int i=0; i< m_dataList.size(); i++)
	{
		StationData data = m_dataList[i];
		QRgb rgb = getGlobalModelInstance()->getSingleStationColor(data);
		int iAllSingleWarningNo = data.getWarningNoSum();
		drawStationRect(&painter, istartRectX, istartRectY, data);
		istartRectX+= 90;
	}

	int iwidget = this->width();
	istartRectX = iwidget-80;
	drawGraphHintInfo(&painter, istartRectX, istartRectY/2);

}


//���ƻ�ͼ���� һ����� �ĸ�С�� ��������� ����ǹ̶���
void SGrapgWidget1::drawAllGraphRect(QPainter *painter)
{
	// ����ɫ
	QRadialGradient gradient;
	gradient.setColorAt(0, Qt::white);
	//	gradient.setColorAt(1.0, Qt::blue);
	painter->setBrush(gradient);

	int iwidth = this->width();
	int iheight = this->height();
	int iLineWidth = 20+m_dataList.size()*90;

	painter->setPen(QPen(Qt::gray,1));
	painter->drawRect(0, 0, iwidth, g_Graph1RectHeight);

	int iStartX = 30;
	int iStartY = g_Graph1RectHeight-20;
	int iLineText = 0;

	//������
	painter->drawLine(iStartX, iStartY, iStartX, iStartY-252);

	//�����ߺ����ֵĻ���
	for (int i=0; i<6; i++)
	{
		painter->setPen(QColor(Qt::black));
		painter->drawText(10, iStartY, QString::number(iLineText));

		painter->setPen(QPen(Qt::gray,1));
		painter->drawLine(iStartX-2, iStartY, iLineWidth, iStartY);
		iStartY -= 50;
		iLineText += 50;
	}
}

void SGrapgWidget1::drawGraphHintInfo(QPainter *painter, int iStartX, int iStartY)
{
	QRadialGradient gradient;
	gradient.setColorAt(0, Qt::white);
	//	gradient.setColorAt(1.0, Qt::blue);
	painter->setBrush(gradient);

	painter->setPen(QColor(Qt::black));
	//���ұߵ� ������״ͼ������Ϣ
	gradient.setColorAt(0, Qt::blue);
	painter->setBrush(gradient);
	painter->drawRect(iStartX, iStartY, -10, -10);
	painter->drawText(iStartX+15, iStartY, "һ������");

	iStartY+=20;
	gradient.setColorAt(1, Qt::red);
	painter->setBrush(gradient);
	painter->drawRect(iStartX, iStartY, -10, -10);
	painter->drawText(iStartX+15, iStartY, "��������");

	iStartY+=20;
	gradient.setColorAt(1, Qt::green);
	painter->setBrush(gradient);
	painter->drawRect(iStartX, iStartY, -10, -10);
	painter->drawText(iStartX+15, iStartY, "��������");
}

//������վһ���rect
void SGrapgWidget1::drawStationRect(QPainter *painter, int iStartX, int iStartY, StationData data)
{
	QRadialGradient gradient;
	gradient.setColorAt(0, Qt::white);
	gradient.setColorAt(1.0, g_BlackColor);
	painter->setBrush(gradient);
	painter->setPen(QColor(Qt::black));//���û�����ɫΪ��ɫ
	painter->drawText(iStartX, iStartY+15, data.strStationName); //������ˮƽ���У�

	//�ֱ𻭳�����rect����
	drawSingleRect(painter, iStartX, iStartY, data.iWarning1No, g_BlueColor);
	drawSingleRect(painter, iStartX+g_iWarningRectWidth, iStartY, data.iWarning2No, g_RedColor);
	drawSingleRect(painter, iStartX+2*g_iWarningRectWidth, iStartY, data.iWarning3No, g_GreenColor);
}

void SGrapgWidget1::drawSingleRect(QPainter *painter,int iStartX, int iStartY, int iheight, QRgb color)
{
	// ����ɫ
	QRadialGradient gradient;
	gradient.setColorAt(0, Qt::white);
	gradient.setColorAt(1.0, color);
	painter->setBrush(gradient);

	painter->setPen(Qt::NoPen);
	//���򻭳���
    painter->drawRect(iStartX, iStartY, g_iWarningRectWidth, -iheight);
}
