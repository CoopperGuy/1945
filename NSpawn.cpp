#include "stdafx.h"
#include "NSpawn.h"
#include "NMonster.h"
#include "ObjMgr.h"
CNSpawn::CNSpawn()
{
}


CNSpawn::~CNSpawn()
{
}

HRESULT CNSpawn::Initialize()
{
	m_dwTime = GetTickCount();
	m_SpwanTime = GetTickCount();
	m_SpawnDelay = 300;
	return S_OK;
}

void CNSpawn::Ready()
{
}

int CNSpawn::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	if (Spawn_Cnt > 0 &&  (m_dwTime + m_dwDelayTime < GetTickCount())) {
		if (Num_of_Spawn > 0 && (m_SpwanTime + m_SpawnDelay < GetTickCount())) {
			CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CNMonster>::Create(m_tInfo.vPos, m_tInfo.vDir), OBJID::MONSTER);
			m_SpwanTime = GetTickCount();
			Num_of_Spawn--;
		}
		if (Num_of_Spawn <= 0) {
			m_dwTime = GetTickCount();
			Spawn_Cnt--;
			Num_of_Spawn = 5;
		}
	}

	return OBJ_NOEVENT;
}

void CNSpawn::Late_Update()
{
	if (Spawn_Cnt == 0)
		m_bDead = OBJ_DEAD;
}

void CNSpawn::Render(HDC _DC)
{
}

void CNSpawn::Release()
{
}
