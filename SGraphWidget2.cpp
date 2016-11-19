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

		//百分比
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
	// 渐变色
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
	// 扇形起始角度  
	painter->setPen(Qt::NoPen);
	painter->drawPie(rect_top, startAngle*16, angleLength*16);

	//在画一条多段线 根据每个扇形的弧度/2 这个斜率 画出一条线 在横向一条  然后+文字
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
