#pragma once
#include "Model.h"

//���Ʋ� �������ݺ�UI
class Controller
{
public:
	Controller(void);
	~Controller(void);

public:
	bool modifyStationData(StationDataType dataType, int iIndex, int value);
};

extern Controller* getGlobalControllerInstance();
