#pragma once

#ifndef __CPLAYER_H__
#define __CPLAYER_H__

#include "Obj.h"
class CPlayer :
	public CObj
{
private:
	CPlayer();
public:
	virtual ~CPlayer();
public:
	virtual HRESULT Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
public:
	static CObj* Create();
public:
	void Set_Power() { if (Power < 3)Power++; }
public:
	bool Get_Move() { return m_bMove; }
private:
	static int Life;
	D3DXVECTOR3 m_dist = { 300.f, 720.f ,0.f };
	int Power = 0;
	int Bomb = 2;
	bool m_bMove = false;
	DWORD m_ltime;
	DWORD m_delay = 600;
};


#endif // !__CPLAYER_H__
