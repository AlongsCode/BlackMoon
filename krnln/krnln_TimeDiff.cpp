#include "stdafx.h"
#include <math.h>

//ʱ����� - ȡʱ����
/*
    ���ø�ʽ�� ��˫����С���͡� ȡʱ���� ������ʱ���� ʱ��1������ʱ���� ʱ��2�������� ȡ������֣� - ϵͳ����֧�ֿ�->ʱ�����
    Ӣ�����ƣ�TimeDiff
    ����һ����ֵ����ʾ��ʱ��1����ȥ��ʱ��2��֮��ļ����Ŀ��ע�⣺ÿ��������������Ϊ��һ�졣������Ϊ�������
    ����<1>������Ϊ��ʱ��1��������Ϊ������ʱ���ͣ�date������
    ����<2>������Ϊ��ʱ��2��������Ϊ������ʱ���ͣ�date������
    ����<3>������Ϊ��ȡ������֡�������Ϊ�������ͣ�int����������ֵָ��ȡʱ�����ĵ�λ������Ϊ���³����� 1��#��ݣ� 2��#���ȣ� 3��#�·ݣ� 4��#�ܣ� 5��#�գ� 6��#Сʱ�� 7��#���ӣ� 8��#�롣
*/

//������ʼ���ڶ�����
//��ʼ���� 1899��12��30�� ��ֵΪ0, Ϊ�������һ��(������)
//-13��-7 �ǵ�-1��
//-6��0 �ǵ�0��
//1��7 �ǵ�1��
double GetWeekDayNum(DATE dt)
{
	INT nRet;
	if ((INT)dt > 0) {
		nRet = ((INT)dt + 6) / 7;
	}
	else {
		nRet = (INT)dt / 7;
	}
	return (double)nRet;
}

LIBAPI(void, krnln_TimeDiff)
{
	PMDATA_INF pArgInf = &ArgInf;
	
	switch(pArgInf[2].m_int)
	{
	case 1://#���
		{
			INT nYear, nMonth, nDay;
			INT nYear1, nMonth1, nDay1;
			GetDatePart(pArgInf[0].m_date, nYear, nMonth, nDay);
			GetDatePart(pArgInf[1].m_date, nYear1, nMonth1, nDay1);
			pArgInf[0].m_date = nYear - nYear1;
			break;
		}
	case 2://#����
		{
			INT nYear, nMonth, nDay;
			INT nYear1, nMonth1, nDay1;
			GetDatePart(pArgInf[0].m_date, nYear, nMonth, nDay);
			GetDatePart(pArgInf[1].m_date, nYear1, nMonth1, nDay1);
			pArgInf[0].m_date = (nYear - nYear1) * 4 + ((nMonth - 1) / 3) - ((nMonth1 - 1) / 3);
			break;
		}
	case 3://#�·�
		{
			INT nYear, nMonth, nDay;
			INT nYear1, nMonth1, nDay1;
			GetDatePart(pArgInf[0].m_date, nYear, nMonth, nDay);
			GetDatePart(pArgInf[1].m_date, nYear1, nMonth1, nDay1);
			pArgInf[0].m_date = (nYear - nYear1) * 12 - nMonth1 + nMonth;
 			break;
		}
	case 4://#��
		{
			DATE objDate, objDate1;
			DATE dt = modf(pArgInf[0].m_date, &objDate);
			dt = modf(pArgInf[1].m_date, &objDate1);

			pArgInf[0].m_date = GetWeekDayNum(objDate) - GetWeekDayNum(objDate1);
			break;
		}
	case 5://#��
		{
			DATE objDate = toMyDate(pArgInf[0].m_date) - toMyDate(pArgInf[1].m_date);
			pArgInf[0].m_date = objDate;
			break;
		}
	case 6://#Сʱ
		{
			DATE objDate = toMyDate(pArgInf[0].m_date) - toMyDate(pArgInf[1].m_date);
			modf(objDate * 24.0 + 0.000005787037037037037, &pArgInf[0].m_date);
			break;
		}
	case 7://#����
		{
			DATE objDate = toMyDate(pArgInf[0].m_date) - toMyDate(pArgInf[1].m_date);
			modf(objDate * 1440.0 + 0.000005787037037037037, &pArgInf[0].m_date);
			break;
		}
	case 8://#�롣
		{
			DATE objDate = toMyDate(pArgInf[0].m_date) - toMyDate(pArgInf[1].m_date);
			modf(objDate * 86400.0 + 0.000005787037037037037, &pArgInf[0].m_date);
			break;
		}
	default:
		pArgInf[0].m_double = 0;

	}
	__asm{
		mov eax, ArgInf.m_unit.m_dwFormID;
		mov edx, ArgInf.m_unit.m_dwUnitID;
	}

}
