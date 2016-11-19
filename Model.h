#pragma once
#include "qstring.h"
#include <vector>
#include "qrgb.h"
#include <map>
#include "const.h"
using namespace std;

//ģ�Ͳ�������
class Model
{
public:
	Model(void);
	~Model(void);
	
	//�õ����г�վ����
	vStationData getStationDataArr();
	
	//�޸�ĳһ����վ����
	bool modifyStationData(StationDataType dataType, int iIndex, int value);

	//�õ����о�������
	int getAllWarningNo();

	//�õ�ĳ����վ�Ļ�ͼ��ɫ
	QRgb getSingleStationColor(StationData data);

private:
	//��ʼ�����г�վ����
	void initAllStationData();

	//��ʼ����ɫֵmap
	void initColorMap();

private:
	vStationData m_AllStationData;
	mQRgbs m_ColorMaps;
};

extern Model* getGlobalModelInstance();


