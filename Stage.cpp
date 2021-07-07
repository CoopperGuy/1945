#include "stdafx.h"
#include "Stage.h"
#include "ObjMgr.h"
#include "Player.h"
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
