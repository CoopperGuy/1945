#pragma once

#ifndef __CPATTERNMGR_H__
#define __CPATTERNMGR_H__

class CPatternMgr
{
public:
	CPatternMgr();
	~CPatternMgr();
public:
	static void Pattern_A(D3DXVECTOR3 _vPos, D3DXVECTOR3 _vDir, DWORD _time, int _Cnt);
	static void Pattern_B(D3DXVECTOR3 _vPos, DWORD _time, int _Cnt);
	static void Pattern_C(DWORD _time, int _Cnt);
	static void Pattern_D(D3DXVECTOR3 _vPos, DWORD _time, int _Cnt);
	static void Pattern_E(D3DXVECTOR3 _vPos, D3DXVECTOR3 _vDist, DWORD _time, int _Cnt);
	static void Pattern_F(DWORD _time, int _Cnt);
};


#endif // !__CPATTERNMGR_H__
