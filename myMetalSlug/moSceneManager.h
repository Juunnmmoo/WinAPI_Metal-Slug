#pragma once
#include "moScene.h"

namespace mo {
	class SceneManager
	{
	public:
		
		static void Initialize();
		static void Update();
		static void Render(HDC mHdc);
		static void Destroy();
		static void Release();

		static void LoadScene(eSceneType type);
		static Scene* GetActiveScene() { return mActiveScene; }

	private:
		static std::vector<Scene*> mScenes;
		static Scene* mActiveScene;
	};
}
