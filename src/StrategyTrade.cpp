#include <vector>
#include <thread>
#include <mutex>
#include "StrategyTrade.h"

// �̻߳�����
std::mutex marketDataMutex;

void StrategyCheckAndTrade(std::string &instrumentID, std::unordered_map<std::string, TickToKlineHelper> &instrumentRecord, reqOrderInsertFun reqFun)
{
	std::lock_guard<std::mutex> lk(marketDataMutex);
	TickToKlineHelper tickToKlineObject = instrumentRecord.at(instrumentID);

		std::vector<double> priceVec = tickToKlineObject.m_priceVec;
		if (priceVec.size() >= 3)
		{
			int len = priceVec.size();
			// ��������������Ǿ��򿪲�,��֮��������
			if (priceVec[len - 1] > priceVec[len - 2] && priceVec[len - 2] > priceVec[len - 3])
				reqFun(instrumentID, priceVec[len - 1], 1, THOST_FTDC_D_Buy);
			else if (priceVec[len - 1] < priceVec[len - 2] && priceVec[len - 2] < priceVec[len - 3])
				reqFun(instrumentStr, priceVec[len - 1], 1, THOST_FTDC_D_Buy);
		}
	}
}
