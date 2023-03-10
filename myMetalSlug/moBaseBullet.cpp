#include "moBaseBullet.h"
#include "moImage.h"
#include "moResources.h"
#include "moTransform.h"
#include "moTime.h"
#include "Collider.h"
#include "moObject.h"

namespace mo {
	BaseBullet::BaseBullet() 
		: mDirection(eDirection::Right)
		, mDir(Vector2(5.0f, 0.0f))
	{
		mDir.Nomalize();
	}
	BaseBullet::~BaseBullet()
	{
	}
	void BaseBullet::Initialize()
	{
		mImage = Resources::Load<Image>(L"OriginalBullet", L"..\\Resources\\OriginalBullet.bmp");


		/*Collider* mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2{ 20.0f, 20.0f });
		mCollider->SetLeftTop(Vector2{ -50.0f, -70.0f });*/

	}
	void BaseBullet::Update()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		/*if(mDirection == eDirection::Right)
			pos.x += 1200.0f * Time::DeltaTime();
		if (mDirection == eDirection::Left)
			pos.x -= 1200.0f * Time::DeltaTime();*/

		pos.x += 1000.0f * mDir.x *Time::DeltaTime();
		pos.y += 1000.0f * mDir.y * Time::DeltaTime();


		tr->SetPos(pos);
	}

	void BaseBullet::Render(HDC mHdc)
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		if (mDirection == eDirection::Right)
			TransparentBlt(mHdc, pos.x + 50.0f, pos.y - 40.0f, 20, 20, mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(153, 217, 234));
		else if (mDirection == eDirection::Left)
			TransparentBlt(mHdc, pos.x - 50.0f, pos.y - 40.0f, 20, 20, mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(153, 217, 234));
		else if (mDirection == eDirection::Top)
			TransparentBlt(mHdc, pos.x - 5.0f, pos.y - 90.0f, 20, 20, mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(153, 217, 234));
	}
	void BaseBullet::OnCollisionEnter(Collider* other, eLayerType otherType)
	{

		
	/*	if (otherType == eLayerType::Monster) {
			object::Destory(this);
		}*/

	}
	void BaseBullet::OnCollisionStay(Collider* other, eLayerType otherType)
	{
	}
	void BaseBullet::OnCollisionExit(Collider* other, eLayerType otherType)
	{
	}
}