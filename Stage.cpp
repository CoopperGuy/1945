#include "stdafx.h"
#include "CollisionMgr.h"
#include "Stage.h"
#include "ObjMgr.h"
#include "Player.h"
#include "Bullet.h"
#include "NMonster.h"
#include "Obj.h"
#include "NSpawn.h"
#include "Item.h"
#include "Boss.h"
#include "PatternMgr.h"
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
	//CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CNMonster>::Create(), OBJID::MONSTER);
	//CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CNSpawn>::Create({ 100.f,-100.f,0.f }, {0.f,1.f,0.f}, 600, 5), OBJID::MONSTERSPAWN);
	//CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CNSpawn>::Create({ 600.f,250.f,0.f }, { -1.f,1.f,0.f }, 300, 5), OBJID::MONSTERSPAWN);
	//CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CBoss>::Create({300.f,150.f,0.f}), OBJID::MONSTER);
	//CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CItem>::Create({ 300.f,250.f,0.f }, { -1.f,1.f,0.f }, 300, 5), OBJID::ITEM);
	CPatternMgr::Pattern_B(D3DXVECTOR3(0.f, -100.f, 0.f), 100, 1);
	CPatternMgr::Pattern_B(D3DXVECTOR3(300.f, -100.f, 0.f), 300, 1);
	CPatternMgr::Pattern_A(D3DXVECTOR3(-100.f, 150.f, 0.f), D3DXVECTOR3(1.f, 0.f, 0.f), 1200, 5);
	CPatternMgr::Pattern_A(D3DXVECTOR3(700.f,  175.f, 0.f), D3DXVECTOR3(-1.f, 0.f, 0.f), 1200, 5);



	CPatternMgr::Pattern_E(D3DXVECTOR3(700.f, 100.f, 0.f), D3DXVECTOR3(350.f, 400.f, 0.f), 4000, 1);
	CPatternMgr::Pattern_E(D3DXVECTOR3(-100.f, 100.f, 0.f), D3DXVECTOR3(200.f, 400.f, 0.f), 5000, 1);


	CPatternMgr::Pattern_A(D3DXVECTOR3(100.f,-100.f,0.f), D3DXVECTOR3(0.f,1.f,0.f), 12000,5);
	CPatternMgr::Pattern_A(D3DXVECTOR3(500.f, -100.f, 0.f), D3DXVECTOR3(0.f, 1.f, 0.f), 12000, 5);

	CPatternMgr::Pattern_C(16000,1);
	CPatternMgr::Pattern_D(D3DXVECTOR3(100.f,-100.f,0.f) , 16000,1);
	CPatternMgr::Pattern_D(D3DXVECTOR3(350.f, -100.f, 0.f), 16000, 1);
	CPatternMgr::Pattern_D(D3DXVECTOR3(480.f, -100.f, 0.f), 16000, 1);

	CPatternMgr::Pattern_E(D3DXVECTOR3(700.f, 100.f, 0.f), D3DXVECTOR3(100.f, 450.f, 0.f), 22000, 1);
	CPatternMgr::Pattern_E(D3DXVECTOR3(-100.f, 100.f, 0.f), D3DXVECTOR3(500.f, 450.f, 0.f), 22000, 1);

	CPatternMgr::Pattern_D(D3DXVECTOR3(100.f, -100.f, 0.f), 25000, 1);
	CPatternMgr::Pattern_D(D3DXVECTOR3(350.f, -100.f, 0.f), 25000, 1);
	CPatternMgr::Pattern_D(D3DXVECTOR3(480.f, -100.f, 0.f), 25000, 1);

	CPatternMgr::Pattern_B(D3DXVECTOR3(0.f, -100.f, 0.f), 27000, 1);
	CPatternMgr::Pattern_B(D3DXVECTOR3(300.f, -100.f, 0.f), 27000, 1);

	CPatternMgr::Pattern_F(33000,1);

}

void CStage::Update()
{
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
