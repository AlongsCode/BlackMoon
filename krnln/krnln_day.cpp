#include "stdafx.h"
#include <math.h>
//ʱ����� - ȡ��
/*
    ���ø�ʽ�� �������͡� ȡ�� ������ʱ���� ʱ�䣩 - ϵͳ����֧�ֿ�->ʱ�����
    Ӣ�����ƣ�day
    ����һ��ֵΪ 1 �� 31 ֮�����������ʾһ�����е�ĳһ�ա�������Ϊ�������
    ����<1>������Ϊ��ʱ�䡱������Ϊ������ʱ���ͣ�date������
*/
LIBAPI(int, krnln_day)
{
	INT nYear, nMonth, nDay;
	GetDatePart(ArgInf.m_date, nYear, nMonth, nDay);
	return nDay;
}
