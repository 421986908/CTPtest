#include <iostream>
#include "CustomMdSpi.h"

void CustomMdSpi::OnFrontConnected()
{
	std::cout << "=====�������ӳɹ�=====" << std::endl;
}

void CustomMdSpi::OnFrontDisconnected(int nReason)
{
	std::cerr << "=====�������ӶϿ��������룺 " << nReason << "=====" << std::endl;
}

void CustomMdSpi::OnHeartBeatWarning(int nTimeLapse)
{
	std::cerr << "=====����������ʱ�����ϴ�����ʱ�䣺 " << nTimeLapse << "=====" << std::endl;
}

void CustomMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{

}