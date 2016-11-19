#include "Controller.h"

Controller* g_pControllerInstance = NULL;

Controller* getGlobalControllerInstance(){
	static Controller* g_pControllerInstance;

	if (!g_pControllerInstance)
	{
		g_pControllerInstance = new Controller();
	}

	return g_pControllerInstance;
}

Controller::Controller(void)
{
}

Controller::~Controller(void)
{
}

bool Controller::modifyStationData(StationDataType dataType, int iIndex, int value){
	return getGlobalModelInstance()->modifyStationData(dataType, iIndex, value);
}
