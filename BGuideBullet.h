#pragma once

#ifndef __CBGUIDEBULLET_H__
#define __CBGUIDEBULLET_H__

#include "Monster.h"
class CBGuideBullet :
	public CMonster
{
public:
	CBGuideBullet();
	virtual ~CBGuideBullet();
public:
	virtual HRESULT Initialize() override;
	virtual void Ready() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
};


#endif // !__CBGUIDEBULLET_H__
