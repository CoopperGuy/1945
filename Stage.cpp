#include "stdafx.h"
#include "CollisionMgr.h"
#include "Stage.h"
#include "ObjMgr.h"
#include "Player.h"
#include "Bullet.h"
#include "NMonster.h"
#include "Obj.h"
CStage::CStage()
{
}


CStage::~CStage()
{

	Release();
}

void CStage::Initialize()
{
	CObjMgr::Get_Instance()->Add_Object(CPlayer::Create(), OBJID::PLAYER);
	//CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CBullet>::Create(), OBJID::PLAYERBULLET);
	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CNMonster>::Create(), OBJID::MONSTER);
}

void CStage::Update()
{
	CObj* temp = CObjMgr::Get_Instance()->Get_Player();

	CObjMgr::Get_Instance()->Update();

}

void CStage::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CStage::Render(HDC _DC)
{
	CObjMgr::Get_Instance()->Render(_DC);

}

void CStage::Release()
{
}
