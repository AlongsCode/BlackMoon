#include "stdafx.h"
#include <math.h>
//ʱ����� - ȡ�·�
/*
    ���ø�ʽ�� �������͡� ȡ�·� ������ʱ���� ʱ�䣩 - ϵͳ����֧�ֿ�->ʱ�����
    Ӣ�����ƣ�month
    ����һ��ֵΪ 1 �� 12 ֮�����������ʾָ��ʱ���е��·ݡ�������Ϊ�������
    ����<1>������Ϊ��ʱ�䡱������Ϊ������ʱ���ͣ�date������

*/
LIBAPI(int, krnln_month)
{
	INT nYear, nMonth, nDay;
	GetDatePart(ArgInf.m_date, nYear, nMonth, nDay);
	return nMonth;
}
