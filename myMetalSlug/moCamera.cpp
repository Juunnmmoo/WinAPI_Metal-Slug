#include "moCamera.h"
#include "moApplication.h"
#include "moGameObject.h"
#include "moTransform.h"
#include "moInput.h"
#include "moTime.h"


extern mo::Application application;

namespace mo{
	
	Vector2 Camera::mReslution = Vector2::Zero;
	Vector2 Camera::mLookPosition = Vector2::Zero;
	Vector2 Camera::mDistance = Vector2::Zero;
	GameObject* Camera::mTarget = nullptr;


	void Camera::Initialize()
	{
		mReslution.x = application.GetWidth();
		mReslution.y = application.GetHeight();
		mLookPosition = mReslution / 2.0f;

	}

	void Camera::Update()
	{

		if (mTarget != nullptr) {
			//Target�� ��ǥ�� �߾����� �ϱ� ���ؼ�,
			mLookPosition = mTarget->GetComponent<Transform>()->GetPos();
		}

		//������ LookPosition�� �����ο�����
		mDistance = mLookPosition - (mReslution / 2.0f);

	}

	void Camera::Clear() {
		
		mReslution.x = application.GetWidth();
		mReslution.y = application.GetHeight();

		mLookPosition = (mReslution / 2.0f);
		mDistance = Vector2::Zero;

	}

}