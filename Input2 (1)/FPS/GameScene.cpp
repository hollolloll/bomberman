#include "pch.h"
#include "GameScene.h"


GameScene::GameScene(class SceneManager* a_pParent) : Scene(a_pParent)
{
}

GameScene::~GameScene()
{
}

eScene GameScene::GetScene()
{
	return eScene::Game;
}
