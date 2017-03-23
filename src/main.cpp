#include <iostream>
#include <string>
#include "CustomMdSpi.h"

using namespace std;

// ���ӿ�
#pragma comment (lib, "thostmduserapi.lib")
#pragma comment (lib, "thosttraderapi.lib")

// ---- ȫ�ֱ��� ---- //
CThostFtdcMdApi *g_pUserApi = nullptr;                             // ����ָ��
char gFontAddr[] = "tcp://180.168.146.187:10010";                  // ģ������ǰ�õ�ַ
TThostFtdcBrokerIDType gBrokerID = "9999";                         // ģ�⾭���̴���
TThostFtdcInvestorIDType gInvesterID = "081097";                   // Ͷ�����˻���
TThostFtdcPasswordType gInvesterPassword = "asdfqwer";             // Ͷ��������
//char *g_pInstrumentID[] = {"TF1706", "al1712", "cs1801", "CF705"}; // �����Լ�����б��С��ϡ���֣��������ѡһ��
char *g_pInstrumentID[] = {"ni1701", "rb1701"};
int instrumentNum = 4;                                             // �����Լ��������

int main()
{
	cout << "��ʼ������..." << endl;
	// ��ʼ������
	g_pUserApi = CThostFtdcMdApi::CreateFtdcMdApi();   // ��������ʵ��
	CThostFtdcMdSpi *pUserSpi = new CustomMdSpi;       // ��������ص�ʵ��
	g_pUserApi->RegisterSpi(pUserSpi);                 // ע���¼���
	g_pUserApi->RegisterFront(gFontAddr);              // ��������ǰ�õ�ַ
	g_pUserApi->Init();                                // ����
	
	// �ȵ��߳��˳�
	g_pUserApi->Join();
	delete pUserSpi;
	g_pUserApi->Release();

	getchar();
	return 0;
}