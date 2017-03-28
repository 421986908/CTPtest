#pragma once
// ---- �򵥲��Խ��׵��� ---- //
#include <string>
#include <unordered_map>
#include "CTP_API/ThostFtdcUserApiStruct.h"
#include "TickToKlineHelper.h"

typedef void(*reqOrderInsertFun)(
	TThostFtdcInstrumentIDType instrumentID,
	TThostFtdcPriceType price,
	TThostFtdcVolumeType volume,
	TThostFtdcDirectionType direction);

void StrategyCheckAndTrade(std::unordered_map<std::string, TickToKlineHelper> &instrumentRecord, reqOrderInsertFun reqFun);
