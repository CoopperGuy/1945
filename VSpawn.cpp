#include "stdafx.h"
#include "VSpawn.h"
#include "ObjMgr.h"
#include "VMonster.h"

CVSpawn::CVSpawn()
{
}


CVSpawn::~CVSpawn()
{
}

HRESULT CVSpawn::Initialize()
{
	m_dwTime = GetTickCount();
	m_SpwanTime = GetTickCount();
	m_SpawnDelay = 300;
	Start_Num = Num_of_Spawn;
	return S_OK;
}

void CVSpawn::Ready()
{
}

int CVSpawn::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	if (Spawn_Cnt > 0 && (m_dwTime + m_dwDelayTime < GetTickCount())) {
		if (Num_of_Spawn > 0 && (m_SpwanTime + m_SpawnDelay < GetTickCount())) {
			CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CVMonster>::Create(m_tInfo.vPos, m_tInfo.vDir, m_dist), OBJID::MONSTER);
			m_SpwanTime = GetTickCount();
			Num_of_Spawn--;
		}
		if (Num_of_Spawn <= 0) {
			m_dwTime = GetTickCount();
			Spawn_Cnt--;
			Num_of_Spawn = Start_Num;
		}
	}

	return OBJ_NOEVENT;
}

void CVSpawn::Late_Update()
{
	if (Spawn_Cnt == 0)
		m_bDead = OBJ_DEAD;
}

void CVSpawn::Render(HDC _DC)
{
}

void CVSpawn::Release()
{
}
