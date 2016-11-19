#pragma once
#include "QWidget"
#include "QVBoxLayout"
#include "QWidget"
#include "const.h"

//车站柱状图自定义组件
class SGrapgWidget1 : public QWidget
{
	Q_OBJECT

public:
	SGrapgWidget1(QWidget *parent);
	SGrapgWidget1();

	virtual void update();

protected:
	//界面绘制
	virtual void paintEvent(QPaintEvent* event);

private:
	void drawAllGraphRect(QPainter *painter);
	void drawStationRect(QPainter *painter,int iStartX, int iStartY, StationData data);
	//绘制单个柱状图
	void drawSingleRect(QPainter *painter,int iStartX, int iStartY, int iheight, QRgb color);
	void drawGraphHintInfo(QPainter *painter, int iStartX, int iStartY);

private:
	//车站数据
	vStationData m_dataList;
};
