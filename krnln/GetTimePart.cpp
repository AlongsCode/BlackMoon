#include "stdafx.h"
#include <math.h>
#include <oleauto.h>
#pragma comment(lib, "OleAut32.lib")

//ȡʱ�䲿��,����1Ϊֻ��ʱ�䲿�ֵ�DATE����
void GetTimePart(DATE dt,INT& nHour,INT& nMinute,INT& nSecond)
{
	SYSTEMTIME st = {0};
	VariantTimeToSystemTime(dt, &st);
	nHour = (INT)st.wHour;
	nMinute = (INT)st.wMinute;
	nSecond = (INT)st.wSecond;
	/*
	INT nSecCount = (INT)DATE( 86400 * fabs(dt)+0.5);//������
	nHour = nSecCount / 3600;
	nSecCount %= 3600;
	nMinute = nSecCount / 60;
	nSecond = nSecCount % 60;
	*/
}