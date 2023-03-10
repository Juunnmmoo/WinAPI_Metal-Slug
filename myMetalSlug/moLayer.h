#pragma once
#include "moEntity.h"
#include "moGameObject.h"

namespace mo {
	class Layer : public Entity
	{
	public:

		Layer();
		~Layer();

		void Initialize();
		void Update();
		void Render(HDC mHdc);

		void AddGameObject(GameObject* obj);
		std::vector<GameObject*>& GetGameObjects() { return mGameObjects; }
	private:

		std::vector<GameObject*> mGameObjects;
	};
}
