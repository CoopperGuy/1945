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

};


#endif // !__CPLAYER_H__
