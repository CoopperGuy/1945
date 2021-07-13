#pragma once

#ifndef __CMONSTER_H__
#define __CMONSTER_H__

#include "Obj.h"
#include "MSfx.h"
class CMonster :
	public CObj
{
public:
	CMonster();
	virtual ~CMonster();

public:
	virtual HRESULT Initialize() PURE;
	virtual void Ready()PURE;
	virtual int Update() PURE;
	virtual void Late_Update() PURE;
	virtual void Render(HDC _DC) PURE;
	virtual void Release() PURE;
public:
	void Set_Cnt(int _cnt) { Spawn_Cnt = _cnt; }
protected:
	int Spawn_Cnt = 1;

};


#endif // !__CMONSTER_H__
