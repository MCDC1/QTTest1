#pragma once
#include "Model.h"

//控制层 隔离数据和UI
class Controller
{
public:
	Controller(void);
	~Controller(void);

public:
	bool modifyStationData(StationDataType dataType, int iIndex, int value);
};

extern Controller* getGlobalControllerInstance();
