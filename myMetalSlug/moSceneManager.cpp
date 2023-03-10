#include "moSceneManager.h"
#include "moTitleScene.h"
#include "moMission1Scene.h"


namespace mo {

	std::vector<Scene*> SceneManager::mScenes;
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::Max);
		mScenes[(UINT)eSceneType::Title] = new TitleScene();
		mScenes[(UINT)eSceneType::Mission1] = new Mission1Scene();

		mActiveScene = mScenes[(UINT)eSceneType::Title];

		mActiveScene->OnEnter();
		for (Scene* scene : mScenes) {
			if (scene == nullptr)
				continue;
			scene->Initialize();
		}
	}
	void SceneManager::Update()
	{
		mActiveScene->Update();
	}
	void SceneManager::Render(HDC mHdc)
	{
		mActiveScene->Render(mHdc);
	}
	void SceneManager::Destroy()
	{
		mActiveScene->Destroy();
	}
	void SceneManager::Release()
	{
		for (Scene* scene : mScenes) {
			if (scene == nullptr)
				continue;
			delete scene;
			scene = nullptr;
		}
	}
	void SceneManager::LoadScene(eSceneType type)
	{
		// ??????
		mActiveScene->OnExit();

		//??????
		mActiveScene = mScenes[(UINT)type];
		mActiveScene->OnEnter();
	}
}