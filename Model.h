#pragma once
#include "qstring.h"
#include <vector>
#include "qrgb.h"
#include <map>
#include "const.h"
using namespace std;

//模型层存放数据
class Model
{
public:
	Model(void);
	~Model(void);
	
	//得到所有车站数据
	vStationData getStationDataArr();
	
	//修改某一个车站数据
	bool modifyStationData(StationDataType dataType, int iIndex, int value);

	//得到所有警报数据
	int getAllWarningNo();

	//得到某个车站的绘图颜色
	QRgb getSingleStationColor(StationData data);

private:
	//初始化所有车站数据
	void initAllStationData();

	//初始化颜色值map
	void initColorMap();

private:
	vStationData m_AllStationData;
	mQRgbs m_ColorMaps;
};

extern Model* getGlobalModelInstance();


