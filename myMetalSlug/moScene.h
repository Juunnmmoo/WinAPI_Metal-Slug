#pragma once
#include "moEntity.h"
#include "moLayer.h"

namespace mo {
	class Scene : public Entity
	{
	public:

		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void Destroy();
		virtual void Render(HDC mHdc)
		{
			for (Layer& layer : mLayers) {
				layer.Render(mHdc);
			}
		}
		
		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* obj, eLayerType layerType);
		std::vector<GameObject*>& GetGameObjects(eLayerType layer);
	private:

		std::vector<Layer> mLayers;
	};
}

