#pragma once
#include "QWidget"
#include "QVBoxLayout"
#include "QWidget"
#include "const.h"

//车站柱状图自定义组件
class SGrapgWidget2 : public QWidget
{
	Q_OBJECT

public:
	SGrapgWidget2(QWidget *parent);
	SGrapgWidget2();
	virtual void update();

protected:
	//界面绘制
	virtual void paintEvent(QPaintEvent* event);

private:
	void drawArc(QPainter *painter, int radius, float startAngle, float angleLength, 
		int arcHeight, QRgb color, QString context);

private:
	//车站数据
	vStationData m_dataList;
};
