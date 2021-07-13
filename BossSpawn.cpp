#include "stdafx.h"
#include "BossSpawn.h"
#include "ObjMgr.h"
#include "Boss.h"

CBossSpawn::CBossSpawn()
{
}


CBossSpawn::~CBossSpawn()
{
	Release();
}

HRESULT CBossSpawn::Initialize()
{
	m_dwTime = GetTickCount();
	m_SpwanTime = GetTickCount();
	m_SpawnDelay = 0;
	return S_OK;
}

void CBossSpawn::Ready()
{
}

int CBossSpawn::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	if (Spawn_Cnt > 0 && (m_dwTime + m_dwDelayTime < GetTickCount())) {
		if (Num_of_Spawn > 0 && (m_SpwanTime + m_SpawnDelay < GetTickCount())) {
			D3DXVECTOR3 temp = { m_tInfo.vPos.x + (Num_of_Spawn) * 50,m_tInfo.vPos.y,m_tInfo.vPos.z };
			CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CBoss>::Create(temp, m_tInfo.vDir), OBJID::MONSTER);
			m_SpwanTime = GetTickCount();
			Num_of_Spawn--;
		}
		if (Num_of_Spawn <= 0) {
			m_dwTime = GetTickCount();
			Spawn_Cnt--;
			Num_of_Spawn = 1;
		}
	}

	return OBJ_NOEVENT;
}

void CBossSpawn::Late_Update()
{
	if (Spawn_Cnt == 0)
		m_bDead = OBJ_DEAD;

}

void CBossSpawn::Render(HDC _DC)
{
}

void CBossSpawn::Release()
{
}
