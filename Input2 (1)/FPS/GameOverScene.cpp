#include "pch.h"
#include "GameOverScene.h"


GameOverScene::GameOverScene(class SceneManager* a_pParent) : Scene(a_pParent)
{
}

GameOverScene::~GameOverScene()
{
}

eScene GameOverScene::GetScene()
{
	return eScene::GameOver;
}
