#include "Model.h"
#include "const.h"
#include "mainwindow.h"


Model *g_pMolelInstance = NULL;

extern Model* getGlobalModelInstance(){
	static Model *g_pMolelInstance;

	if (!g_pMolelInstance)
	{
		g_pMolelInstance = new Model();
	}

	return g_pMolelInstance;
}

Model getDataInstance(){
	static Model g_DataInstance;
	return g_DataInstance;
}

Model::Model(){
	initAllStationData();
	initColorMap();
}

Model::~Model(void){
	m_AllStationData.clear();
	m_ColorMaps.clear();
}

void Model::initColorMap(){
	m_ColorMaps["color1"] = g_BlueColor;
	m_ColorMaps["color2"] = g_RedColor;
	m_ColorMaps["color3"] = g_GreenColor;
	m_ColorMaps["color4"] = qRgb(154, 37, 48);
	m_ColorMaps["color5"] = qRgb(50, 200, 14);
	m_ColorMaps["color6"] = qRgb(18, 60, 200);
	m_ColorMaps["color7"] = qRgb(0, 0, 0);
	m_ColorMaps["color8"] = qRgb(150, 150, 150);
	m_ColorMaps["color9"] = qRgb(40, 30, 40);
	m_ColorMaps["color10"] = qRgb(50,70, 200);
	m_ColorMaps["color11"] = qRgb(70, 60, 160);
	m_ColorMaps["color12"] = qRgb(70, 40, 220);
	m_ColorMaps["color13"] = qRgb(80, 30, 150);
	m_ColorMaps["color14"] = qRgb(200, 145, 90);
	m_ColorMaps["color15"] = qRgb(100, 100, 255);

}

void Model::initAllStationData(){
	StationData data;
	data.strStationName = "控制中心";
	data.iWarning1No = 98;
	data.iWarning2No = 96;
	data.iWarning3No = 195;
	data.strColorId = "color1";
	m_AllStationData.push_back(StationData(data));

	StationData data2;
	data2.strStationName = "备用中心";
	data2.iWarning1No = 126;
	data2.iWarning2No = 127;
	data2.iWarning3No = 35;
	data2.strColorId = "color2";
	m_AllStationData.push_back(StationData(data2));

	data.strStationName = "燕化站";
	data.iWarning1No = 64;
	data.iWarning2No = 50;
	data.iWarning3No = 59;
	data.strColorId = "color3";
	m_AllStationData.push_back(StationData(data));

	data.strStationName = "老城区北";
	data.iWarning1No = 27;
	data.iWarning2No = 104;
	data.iWarning3No = 27;
	data.strColorId = "color4";
	m_AllStationData.push_back(StationData(data));

	data.strStationName = "饶乐府";
	data.iWarning1No = 180;
	data.iWarning2No = 107;
	data.iWarning3No = 187;
	data.strColorId = "color5";
	m_AllStationData.push_back(StationData(data));

	data.strStationName = "顾八路";
	data.iWarning1No = 122;
	data.iWarning2No = 72;
	data.iWarning3No = 170;
	data.strColorId = "color6";
	m_AllStationData.push_back(StationData(data));

	data.strStationName = "星城站";
	data.iWarning1No = 103;
	data.iWarning2No = 144;
	data.iWarning3No = 39;
	data.strColorId = "color7";
	m_AllStationData.push_back(StationData(data));

	data.strStationName = "阎村站";
	data.iWarning1No = 151;
	data.iWarning2No = 158;
	data.iWarning3No = 169;
	data.strColorId = "color8";
	m_AllStationData.push_back(StationData(data));

	data.strStationName = "大紫草乌";
	data.iWarning1No = 101;
	data.iWarning2No = 189;
	data.iWarning3No = 23;
	data.strColorId = "color9";
	m_AllStationData.push_back(StationData(data));

	data.strStationName = "阎村北";
	data.iWarning1No = 88;
	data.iWarning2No = 39;
	data.iWarning3No = 33;
	data.strColorId = "color10";
	m_AllStationData.push_back(StationData(data));

	StationData data10;

	data10.strStationName = "周口店镇";
	data10.iWarning1No = 91;
	data10.iWarning2No = 75;
	data10.iWarning3No = 3;
	data10.strColorId = "color11";
	m_AllStationData.push_back(StationData(data10));

	data.strStationName = "顾删站";
	data.iWarning1No = 197;
	data.iWarning2No = 41;
	data.iWarning3No = 81;
	data.strColorId = "color12";
	m_AllStationData.push_back(StationData(data));

	data.strStationName = "老城区";
	data.iWarning1No = 103;
	data.iWarning2No = 117;
	data.iWarning3No = 39;
	data.strColorId = "color13";
	m_AllStationData.push_back(StationData(data));

	data.strStationName = "停车场";
	data.iWarning1No = 149;
	data.iWarning2No = 90;
	data.iWarning3No = 106;
	data.strColorId = "color14";
	m_AllStationData.push_back(StationData(data));

	data.strStationName = "孤星区间";
	data.iWarning1No = 159;
	data.iWarning2No = 171;
	data.iWarning3No = 61;
	data.strColorId = "color15";
	m_AllStationData.push_back(StationData(data));
	m_AllStationData.push_back(StationData(data));
	m_AllStationData.push_back(StationData(data));
	m_AllStationData.push_back(StationData(data));
	m_AllStationData.push_back(StationData(data));
	m_AllStationData.push_back(StationData(data));
	m_AllStationData.push_back(StationData(data));
	m_AllStationData.push_back(StationData(data));
	m_AllStationData.push_back(StationData(data));
	m_AllStationData.push_back(StationData(data));
	m_AllStationData.push_back(StationData(data));
	m_AllStationData.push_back(StationData(data));

}

QRgb Model::getSingleStationColor(StationData data){

	//如果是白色说明没找到
	QRgb rgb = qRgb(255, 255, 255);
	mQRgbs::iterator it = m_ColorMaps.find(data.strColorId);

	if (m_ColorMaps.end() !=  it)
	{
		rgb = m_ColorMaps[data.strColorId];
	}

	return rgb;
}

int Model::getAllWarningNo(){
	int iAllWarningNo = 0;

	for (int i=0; i< m_AllStationData.size(); i++)
	{
		StationData data = m_AllStationData[i];
		iAllWarningNo += data.getWarningNoSum();
	}

	return iAllWarningNo;
}

vStationData Model::getStationDataArr(){
	return m_AllStationData;
}

//修改数据刷新ui
bool Model::modifyStationData(StationDataType dataType, int iIndex, int value)
{
	bool bModify = false;

	if (0 <= iIndex && iIndex < m_AllStationData.size())
	{
		bModify = true;

		if (eWarnning1Type == dataType)
		{
			m_AllStationData[iIndex].iWarning1No = value;
		}
		else if (eWarnning2Type == dataType)
		{
			m_AllStationData[iIndex].iWarning2No = value;
		}
		else if (eWarnning3Type == dataType)
		{
			m_AllStationData[iIndex].iWarning3No = value;
		}
		else{
			bModify = false;
		}
	}

	if (bModify)
	{
		MainWindow::MainWindowInstance->refreshAllStationData();
	}

	return bModify;
}
