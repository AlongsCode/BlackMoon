#include "stdafx.h"

// ���ø�ʽ�� ���ı��͡� UTF8���ı� ���ֽڼ� ��ת����UTF8�ı����ݣ� - ϵͳ����֧�ֿ�->�ı�����
// Ӣ�����ƣ�UTF8ToStr
// ����ָ��UTF8�ı�����ת����ͨ���ı��󷵻ء�������Ϊ�������
// ����<1>������Ϊ����ת����UTF8�ı����ݡ�������Ϊ���ֽڼ���bin�������ṩ��ת����ͨ���ı���UTF8�ı����ݡ�
// 
// ����ϵͳ���� Windows��Linux
LIBAPI(char*, krnln_UTF8ToStr)
{
	char* pSrc;
	int nl, al;
	WCHAR *unicodetext;

	if(ArgInf.m_pBin == NULL) return NULL;
	if (ArgInf.m_pInt[1] <= 0) return NULL;

	pSrc = (char*)ArgInf.m_pBin;
	pSrc += 2*sizeof(INT);

	//�ȴ�UTF-8ת��UNICODE
	nl = MultiByteToWideChar(CP_UTF8, 0, pSrc, -1, NULL, 0);
	if (nl <= 0) return NULL;

	unicodetext = new WCHAR[nl];
	nl = MultiByteToWideChar(CP_UTF8, 0, pSrc, -1, unicodetext, nl);
	if (0 >= nl)
	{
		delete []unicodetext;
		return NULL;
	}
	unicodetext[nl - 1] = 0;

	//����UNICDOEת��ANSI
	al = WideCharToMultiByte(936, 0, unicodetext, -1, NULL, 0, NULL, NULL);
	pSrc = NULL;
	if (al > 0)
	{
		pSrc = (char*)E_MAlloc_Nzero(al);
		if (pSrc)
		{
			al = WideCharToMultiByte(936, 0, unicodetext, -1, pSrc, al, NULL, NULL);
			if (0 >= al)
			{
				delete []unicodetext;
				E_MFree(pSrc);
				return NULL;
			}
			pSrc[al - 1] = 0;
		}
	}
	delete []unicodetext;
	return pSrc;
}
