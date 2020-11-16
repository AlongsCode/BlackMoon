#include "stdafx.h"
#include <math.h>

#include <oleauto.h>
#pragma comment(lib, "OleAut32.lib")

//ʱ����� - ����ʱ��
/*void GetDatePart(DATE dt,INT& nYear,INT& nMonth,INT& nDay)
    ���ø�ʽ�� ������ʱ���͡� ����ʱ�� ������ʱ���� ʱ�䣬������ �����Ӳ��֣������� ����ֵ�� - ϵͳ����֧�ֿ�->ʱ�����
    Ӣ�����ƣ�TimeChg
    ����һ��ʱ�䣬��һʱ�䱻���ϻ��ȥ��һ�μ��������ı���ʱ����Ч�����Զ������������Чʱ�䡣������Ϊ�������
    ����<1>������Ϊ��ʱ�䡱������Ϊ������ʱ���ͣ�date������
    ����<2>������Ϊ�������Ӳ��֡�������Ϊ�������ͣ�int����������ֵָ�����ӻ����ʱ�����һ���֣�����Ϊ���³�����
	1��#��ݣ� 2��#���ȣ� 3��#�·ݣ� 4��#�ܣ� 5��#�գ� 6��#Сʱ�� 7��#���ӣ� 8��#�롣
    ����<3>������Ϊ������ֵ��������Ϊ�������ͣ�int����������ڱ����Ӳ��ֵ����ӻ������ֵ��
*/
LIBAPI(void, krnln_TimeChg)
{
	PMDATA_INF pArgInf = &ArgInf;

	SYSTEMTIME st = {0};
	VariantTimeToSystemTime(pArgInf[0].m_date, &st);

	switch(pArgInf[1].m_int)
	{
	case 1://#���
		{
			st.wYear += pArgInf[2].m_int;
			if(st.wMonth == 2 && st.wDay == 29)
				st.wDay = GetDaysOfSpecMonth(st.wYear, 2);

			SystemTimeToVariantTime(&st, &pArgInf[0].m_date);
			break;
		}
	case 2://#����
		{
			INT nMonth;
			nMonth = st.wMonth + (pArgInf[2].m_int * 3);
			if(nMonth>0)
			{
				st.wYear += (nMonth / 12);
				nMonth %= 12;
			}
			else
			{
				INT decYear = nMonth / 12;
				if(nMonth % 12 != 0)
					decYear--;
				st.wYear += decYear;
				nMonth = 12 + (nMonth % 12);
			}
			st.wMonth = nMonth;

			INT nMaxDay = GetDaysOfSpecMonth(st.wYear, nMonth);
			if(st.wDay > nMaxDay)
				st.wDay = nMaxDay;

			SystemTimeToVariantTime(&st, &pArgInf[0].m_date);
			break;
		}
	case 3://#�·�
		{
			INT nMonth;

			nMonth = st.wMonth + pArgInf[2].m_int;
			if(nMonth > 0)
			{
				if(nMonth > 12)
					st.wYear += (nMonth / 12);
				nMonth %= 12;
				if(nMonth == 0)
					nMonth = 12;

			}
			else
			{
				INT decYear = nMonth / 12;
				if(nMonth % 12 !=0 || nMonth ==0)
					decYear--;
				st.wYear += decYear;
				nMonth = 12 + (nMonth % 12);
			}
			st.wMonth = nMonth;

			INT nMaxDay = GetDaysOfSpecMonth(st.wYear, nMonth);
			if(st.wDay > nMaxDay)
				st.wDay = nMaxDay;
			
			SystemTimeToVariantTime(&st, &pArgInf[0].m_date);
			break;
		}
	case 4://#��
		{
			DATE objDate;
			DATE dt = modf(pArgInf[0].m_date, &objDate);
			objDate += (7 * pArgInf[2].m_int);
			pArgInf[0].m_date = makedb(objDate, dt);
			break;
		}
	case 5://#��
		{
			DATE objDate;
			DATE dt = modf(pArgInf[0].m_date, &objDate);
			objDate += pArgInf[2].m_int;
			pArgInf[0].m_date = makedb(objDate, dt);
			break;
		}
	case 6://#Сʱ
		{
			SystemTimeToVariantTime(&st, &pArgInf[0].m_date); //��ֹ��������ʱ�侫��Խ��Խ��
			pArgInf[0].m_date = toMyDate(pArgInf[0].m_date);
			pArgInf[0].m_date += double(pArgInf[2].m_int) / 24.0;
			pArgInf[0].m_date = toEDate(pArgInf[0].m_date);
			break;
		}
	case 7://#����
		{
			SystemTimeToVariantTime(&st, &pArgInf[0].m_date); //��ֹ��������ʱ�侫��Խ��Խ��
			pArgInf[0].m_date = toMyDate(pArgInf[0].m_date);
			pArgInf[0].m_date += double(pArgInf[2].m_int) / 1440.0;
			pArgInf[0].m_date = toEDate(pArgInf[0].m_date);
			break;
		}
	case 8://#�롣
		{
			SystemTimeToVariantTime(&st, &pArgInf[0].m_date); //��ֹ��������ʱ�侫��Խ��Խ��
			pArgInf[0].m_date = toMyDate(pArgInf[0].m_date);
			pArgInf[0].m_date += double(pArgInf[2].m_int) / 86400.0;
			pArgInf[0].m_date = toEDate(pArgInf[0].m_date);
			break;
		}
	}
	__asm{
		mov eax, ArgInf.m_unit.m_dwFormID;
		mov edx, ArgInf.m_unit.m_dwUnitID;
	}

}
