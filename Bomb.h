#pragma once

#ifndef __CBOMB_H__
#define __CBOMB_H__

#include "Obj.h"
#include "Player.h"
class CBomb :
	public CObj
{
public:
	CBomb();
	virtual ~CBomb();

public:
	virtual HRESULT Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
private:
	DWORD m_time;
	DWORD m_delay;
	D3DXVECTOR3 m_pPos;
	float y;
};



#endif // !__CBOMB_H__
