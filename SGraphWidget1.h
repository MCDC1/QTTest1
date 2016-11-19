#pragma once
#include "QWidget"
#include "QVBoxLayout"
#include "QWidget"
#include "const.h"

//��վ��״ͼ�Զ������
class SGrapgWidget1 : public QWidget
{
	Q_OBJECT

public:
	SGrapgWidget1(QWidget *parent);
	SGrapgWidget1();

	virtual void update();

protected:
	//�������
	virtual void paintEvent(QPaintEvent* event);

private:
	void drawAllGraphRect(QPainter *painter);
	void drawStationRect(QPainter *painter,int iStartX, int iStartY, StationData data);
	//���Ƶ�����״ͼ
	void drawSingleRect(QPainter *painter,int iStartX, int iStartY, int iheight, QRgb color);
	void drawGraphHintInfo(QPainter *painter, int iStartX, int iStartY);

private:
	//��վ����
	vStationData m_dataList;
};
