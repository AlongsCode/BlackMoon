#include "stdafx.h"
#include <math.h>
//ʱ����� - ȡʱ�䲿��
/*
    ���ø�ʽ�� �������͡� ȡʱ�䲿�� ������ʱ���� ��ȡ�䲿�ֵ�ʱ�䣬������ ��ȡ��ʱ�䲿�֣� - ϵͳ����֧�ֿ�->ʱ�����
    Ӣ�����ƣ�TimePart
    ����һ��������֪ʱ��ָ�����ֵ�������������Ϊ�������
    ����<1>������Ϊ����ȡ�䲿�ֵ�ʱ�䡱������Ϊ������ʱ���ͣ�date������
    ����<2>������Ϊ����ȡ��ʱ�䲿�֡�������Ϊ�������ͣ�int����������ֵ����Ϊ���³�����
	1��#��ݣ� 2��#���ȣ� 3��#�·ݣ� 4��#������������ 5��#�գ� 6��#Сʱ�� 7��#���ӣ� 8��#�룻 9��#���ڼ��� 10��#���������������У��������������������������� 1 ��ʼ��
*/
INT GetDaysFromYear(DATE date)
{
	INT nYear, nMonth, nDay;
	GetDatePart(date, nYear, nMonth, nDay);
	INT nCountDay = nDay;
	for(INT i = 1; i < nMonth; i++)
		nCountDay += GetDaysOfSpecMonth(nYear, i);
	return nCountDay;
}

LIBAPI(int, krnln_TimePart)
{
	PMDATA_INF pArgInf = &ArgInf;
	INT nRet = 0;
	switch(pArgInf[1].m_int)
	{
	case 1://#���
		{
			INT nYear, nMonth, nDay;
			GetDatePart(pArgInf[0].m_date, nYear, nMonth, nDay);
			nRet = nYear;
			break;
		}
	case 2://#����
		{
			INT nYear, nMonth, nDay;
			GetDatePart(pArgInf[0].m_date, nYear, nMonth, nDay);
			nRet = nMonth / 3;
			if(nMonth % 3) nRet++;
			break;
		}
	case 3://#�·�
		{
			INT nYear, nMonth, nDay;
			GetDatePart(pArgInf[0].m_date, nYear, nMonth, nDay);
			nRet = nMonth;
			break;
		}
	case 4://#����������
		{
			INT nCountDay = GetDaysFromYear(pArgInf[0].m_date);
			nRet = nCountDay / 7;
			if(nCountDay % 7) nRet++;
			break;
		}
	case 5://#��
		{
			INT nYear, nMonth, nDay;
			GetDatePart(pArgInf[0].m_date, nYear, nMonth, nDay);
			nRet = nDay;
			break;
		}
	case 6://#Сʱ
		{
			INT nHour, nMinute, nSecond;
			GetTimePart(pArgInf[0].m_date, nHour, nMinute, nSecond);
			nRet = nHour;
			break;
		}
	case 7://#����
		{
			INT nHour, nMinute, nSecond;
			GetTimePart(pArgInf[0].m_date, nHour, nMinute, nSecond);
			nRet = nMinute;
			break;
		}
	case 8://#�롣
		{
			INT nHour, nMinute, nSecond;
			GetTimePart(pArgInf[0].m_date, nHour, nMinute, nSecond);
			nRet = nSecond;
			break;
		}
	case 9://#���ڼ�
		{
			nRet = GetWeekDay(pArgInf[0].m_date);
			break;
		}
	case 10://#����������
		{
			nRet = GetDaysFromYear(pArgInf[0].m_date);
			break;
		}
	}
	return nRet ;
}
