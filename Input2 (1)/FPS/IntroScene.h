#pragma once
#include "Scene.h"

class IntroScene : public Scene
{
public:
	IntroScene(class SceneManager* a_pParent);
	virtual ~IntroScene();

	// Scene��(��) ���� ��ӵ�
	virtual eScene GetScene() override;

	virtual void Update(float a_fDeltaTime) override;
	virtual void Render() override;

};