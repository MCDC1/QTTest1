#pragma once
#include "QWidget"
#include "QVBoxLayout"
#include "QWidget"
#include "const.h"

//��վ��״ͼ�Զ������
class SGrapgWidget2 : public QWidget
{
	Q_OBJECT

public:
	SGrapgWidget2(QWidget *parent);
	SGrapgWidget2();
	virtual void update();

protected:
	//�������
	virtual void paintEvent(QPaintEvent* event);

private:
	void drawArc(QPainter *painter, int radius, float startAngle, float angleLength, 
		int arcHeight, QRgb color, QString context);

private:
	//��վ����
	vStationData m_dataList;
};
