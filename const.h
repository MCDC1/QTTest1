#pragma once
#include <vector>
#include <map>
#include <QPainter>
using namespace std;

enum StationDataType{
	eWarnning1Type =  0,
	eWarnning2Type =  1,
	eWarnning3Type =  2,
	eColorId =  3,
};

struct StationData
{
	QString strStationName;
	int iWarning1No;
	int iWarning2No;
	int iWarning3No;

	int getWarningNoSum(){
		return iWarning1No+iWarning2No+iWarning3No;
	}

	QString strColorId;
};

typedef QVector <StationData> vStationData;
typedef map<QString, QRgb> mQRgbs;


//��״ͼ���
const int g_iWarningRectWidth = 20;

//��״ͼ��ʼy����
const int g_Graph1RectHeight = 300;

//�����������ֵ
const int g_iWarningRectMaxHeight = 250;

//����ֱ��
const int g_radius = 100*2;

//����ԭ��x����
const int g_CircleCenterX = 500;

//������ɫֵ
const QRgb g_RedColor = qRgb(255,0,0);
const QRgb g_GreenColor = qRgb(0,255,0);
const QRgb g_BlueColor = qRgb(0,0,255);
const QRgb g_BlackColor = qRgb(0,0,0);
