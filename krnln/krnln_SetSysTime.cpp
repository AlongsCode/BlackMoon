#include "stdafx.h"
#include <math.h>
#include <oleauto.h>
#pragma comment(lib, "OleAut32.lib")

//ʱ����� - ������ʱ��
/*
    ���ø�ʽ�� ���߼��͡� ������ʱ�� ������ʱ���� �����õ�ʱ�䣩 - ϵͳ����֧�ֿ�->ʱ�����
    Ӣ�����ƣ�SetSysTime
    ���õ�ǰϵͳ���ڼ�ʱ�䡣�ɹ������棬ʧ�ܷ��ؼ١�������Ϊ�������
    ����<1>������Ϊ�������õ�ʱ�䡱������Ϊ������ʱ���ͣ�date������
*/
LIBAPI(BOOL, krnln_SetSysTime)
{
	SYSTEMTIME now = { 0 };
	VariantTimeToSystemTime(ArgInf.m_date, &now);
	return SetLocalTime(&now);
}
