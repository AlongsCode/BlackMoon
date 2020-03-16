#include "stdafx.h"

//��ֵת�� - ��������
/*
    ���ø�ʽ�� ���������͡� �������� ��ͨ���� ��ת�����ı�����ֵ�� - ϵͳ����֧�ֿ�->��ֵת��
    Ӣ�����ƣ�ToLong
    ���ذ������ı��ڵĳ�����ֵ���ı�����һ���ʵ����͵���ֵ��֧��ȫ����д��ʽ��������Ҳ���������������͵�����ת��Ϊ��������������Ϊ�������
    ����<1>������Ϊ����ת�����ı�����ֵ��������Ϊ��ͨ���ͣ�all������
*/
LIBAPI(void, krnln_ToLong)
{
	INT64 nRet=0;
	switch(ArgInf.m_dtDataType)
	{
	case SDT_BYTE:
	case SDT_BOOL:
		nRet = ArgInf.m_byte;
		break;
	case SDT_SHORT:
		nRet = ArgInf.m_short;
		break;
	case SDT_TEXT:
		{
			char* pStr = krnln_BJCase(1,ArgInf);
			if(pStr)
			{
				nRet = _atoi64(pStr);
				ArgInf.m_int64 = nRet;
				E_MFree(pStr);
			}
		}
		break;
	case SDT_FLOAT:
		nRet = (INT64)ArgInf.m_float;
		break;
	case SDT_DOUBLE:
		nRet = (INT64)ArgInf.m_double;
		break;
	case SDT_SUB_PTR:
	case SDT_INT:
		nRet = ArgInf.m_int;
		break;
	case SDT_INT64:
		nRet = ArgInf.m_int64;
		break;
	default:
		break;
	}
	ArgInf.m_int64 = nRet;
	__asm{
		mov eax, ArgInf.m_unit.m_dwFormID;
		mov edx, ArgInf.m_unit.m_dwUnitID;
	}
}
