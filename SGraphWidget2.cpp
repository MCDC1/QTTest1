#include "const.h"
#include "SGraphWidget2.h"
#include "Model.h"

SGrapgWidget2::SGrapgWidget2(QWidget *parent)
	: QWidget(parent)
{
	m_dataList = getGlobalModelInstance()->getStationDataArr();
}

SGrapgWidget2::SGrapgWidget2()
{
}

void SGrapgWidget2::update()
{
	QWidget::update();
	m_dataList = getGlobalModelInstance()->getStationDataArr();
}

void SGrapgWidget2::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	
	int radius = g_radius;
	int arcHeight = 40;
	float startAngle = 0.0; 
	int iAllWarningNo = getGlobalModelInstance()->getAllWarningNo();

	for (int i=0; i< m_dataList.size(); i++)
	{
		StationData data = m_dataList[i];
		QRgb rgb = getGlobalModelInstance()->getSingleStationColor(data);
		int iAllSingleWarningNo = data.getWarningNoSum();

		//�ٷֱ�
		float ftemp= (float)100*iAllSingleWarningNo/iAllWarningNo;
		QString temp = QString::number(ftemp, 'f', 2) +"%";
		QString context = data.strStationName;
// 		context += "/r";
		context +=temp;
		float angleLength = (float)360*iAllSingleWarningNo/iAllWarningNo;
		drawArc(&painter, radius, startAngle,  angleLength, arcHeight, rgb, context);
		startAngle += angleLength;
	}

}

void SGrapgWidget2::drawArc(QPainter *painter, int radius, float startAngle, float angleLength, 
	int arcHeight, QRgb color, QString context)
{
	// ����ɫ
	QRadialGradient gradient(0, 0, radius);
	gradient.setColorAt(0, color);
	gradient.setColorAt(1.0, color);
	painter->setBrush(gradient);

	int iwidth = this->width();
	int iheight = this->height();
	int circilRadius = radius/2;

	int rectX = iwidth/2-circilRadius;
	int rectY = circilRadius;

	int cricleX = rectX+circilRadius;
	int cricleY = rectY+circilRadius;

	QRectF rect_top(rectX, rectY, radius, radius);  
	// ������ʼ�Ƕ�  
	painter->setPen(Qt::NoPen);
	painter->drawPie(rect_top, startAngle*16, angleLength*16);

	//�ڻ�һ������� ����ÿ�����εĻ���/2 ���б�� ����һ���� �ں���һ��  Ȼ��+����
	QPointF ptCircleCenter = QPointF(0, 0);
	int iLinelength = g_CircleCenterX+20;

	QPen linePen;
	linePen.setColor(color);
	linePen.setMiterLimit(1);

	painter->setPen(linePen);
	QLineF verRightLine = QLine(cricleX, cricleY, cricleX+circilRadius+40, cricleY);
	verRightLine.setAngle(startAngle+angleLength/2);

	QPointF startpoint = verRightLine.p2();
	QPointF endpoint = startpoint;

	painter->drawLine(verRightLine);

	painter->setPen(QColor(Qt::black));

	int testSize = context.size();
	int textX = endpoint.rx();
	int angleValue = startAngle+angleLength;

	if (angleValue>90 && angleValue<270)
	{
		textX -=40;
	}

	painter->drawText(textX, endpoint.ry(), context);
	// 	painter->drawLine(verRightLine);

	// 	QPointF ptCircleCenter111 = QPointF(100, 100);
	// 	QLine test(const(ptCircleCenter), ptCircleCenter111);
	// 	painter->drawLine((const)test);
}
