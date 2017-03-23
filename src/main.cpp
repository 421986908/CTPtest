#include <iostream>
#include <string>
#include "CustomMdSpi.h"
#include "CustomTradeSpi.h"

using namespace std;

// ���ӿ�
#pragma comment (lib, "thostmduserapi.lib")
#pragma comment (lib, "thosttraderapi.lib")

// ---- ȫ�ֱ��� ---- //
// ��������
TThostFtdcBrokerIDType gBrokerID = "9999";                         // ģ�⾭���̴���
TThostFtdcInvestorIDType gInvesterID = "081097";                   // Ͷ�����˻���
TThostFtdcPasswordType gInvesterPassword = "asdfqwer";             // Ͷ��������
// �������
CThostFtdcMdApi *g_pMdUserApi = nullptr;                           // ����ָ��
char gMdFrontAddr[] = "tcp://180.168.146.187:10010";               // ģ������ǰ�õ�ַ
char *g_pInstrumentID[] = {"TF1706", "al1712", "cs1801", "CF705"}; // �����Լ�����б��С��ϡ���֣��������ѡһ��
int instrumentNum = 4;                                             // �����Լ��������
// ���ײ���
CThostFtdcTraderApi *g_pTradeUserApi = nullptr;                    // ����ָ��
char gTradeFrontAddr[] = "tcp://180.168.146.187:10000";            // ģ�⽻��ǰ�õ�ַ
TThostFtdcInstrumentIDType g_pTradeInstrumentID = "zn1705";        // �����׵ĺ�Լ����
TThostFtdcDirectionType gTradeDirection = THOST_FTDC_D_Sell;       // ��������
TThostFtdcPriceType gLimitPrice = 23135;                            // ���׼۸�

int main()
{
	//cout << "��ʼ������..." << endl;
	//// ��ʼ������
	//g_pMdUserApi = CThostFtdcMdApi::CreateFtdcMdApi();   // ��������ʵ��
	//CThostFtdcMdSpi *pMdUserSpi = new CustomMdSpi;       // ��������ص�ʵ��
	//g_pMdUserApi->RegisterSpi(pMdUserSpi);               // ע���¼���
	//g_pMdUserApi->RegisterFront(gMdFrontAddr);           // ��������ǰ�õ�ַ
	//g_pMdUserApi->Init();                                // ����
	//
	//// �ȵ��߳��˳�
	//g_pMdUserApi->Join();
	//delete pMdUserSpi;
	//g_pMdUserApi->Release();

	cout << "��ʼ������..." << endl;
	g_pTradeUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi();
	CThostFtdcTraderSpi *pTradeSpi = new CustomTradeSpi;
	g_pTradeUserApi->RegisterSpi(pTradeSpi);
	g_pTradeUserApi->SubscribePublicTopic(THOST_TERT_RESTART);
	g_pTradeUserApi->SubscribePrivateTopic(THOST_TERT_RESTART);
	g_pTradeUserApi->RegisterFront(gTradeFrontAddr);
	g_pTradeUserApi->Init();

	g_pTradeUserApi->Join();
	delete pTradeSpi;
	g_pTradeUserApi->Release();
	

	getchar();
	return 0;
}