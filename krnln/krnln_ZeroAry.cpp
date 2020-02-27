#include "stdafx.h"

/*
    ���ø�ʽ�� ���޷���ֵ�� �������� ��ͨ���ͱ������� ��ֵ��������� - ϵͳ����֧�ֿ�->�������
    Ӣ�����ƣ�ZeroAry
    ��ָ����ֵ��������ڵ����г�Աֵȫ������Ϊ�㣬��Ӱ�������ά������Ϣ��������Ϊ�������
    ����<1>������Ϊ����ֵ���������������Ϊ��ͨ���ͣ�all�������ṩ��������ʱֻ���ṩ�������顣
*/

LIBAPI(void, krnln_ZeroAry)
{
	// no data
	if(!ArgInf.m_ppAryData)
		return;

	// not supported data type
	if(ArgInf.m_dtDataType==SDT_TEXT || ArgInf.m_dtDataType==SDT_BIN)
		return;
	
	// get single element size
	// user defined struct is NOT supported, nLen will be zero
	DWORD dwElementSize = (DWORD)GetSysDataTypeDataSize(ArgInf.m_dtDataType);
	if(!dwElementSize)
		return;

	// get first element and array length
	DWORD dwArrayLen = 0;
	void* pFirstElement = GetAryElementInf(*ArgInf.m_ppAryData, dwArrayLen);
	if(!pFirstElement || !dwArrayLen)
		return;

	// zero all element
	memset(pFirstElement, 0, dwElementSize * dwArrayLen);	
}