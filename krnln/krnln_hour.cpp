#include "stdafx.h"
#include <math.h>
//ʱ����� - ȡСʱ
/*
    ���ø�ʽ�� �������͡� ȡСʱ ������ʱ���� ʱ�䣩 - ϵͳ����֧�ֿ�->ʱ�����
    Ӣ�����ƣ�hour
    ����һ��ֵΪ 0 �� 23 ֮�����������ʾһ���е�ĳһСʱ��������Ϊ�������
    ����<1>������Ϊ��ʱ�䡱������Ϊ������ʱ���ͣ�date������
*/
LIBAPI(int, krnln_hour)
{
	INT nHour, nMinute, nSecond;
	GetTimePart(ArgInf.m_date, nHour, nMinute, nSecond);
	return nHour;
}
