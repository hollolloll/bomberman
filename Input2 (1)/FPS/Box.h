#pragma once
#include "Object.h"
class Box :
	public Object
{
public:
	Box(int x, int y);
	virtual ~Box();



	// Object��(��) ���� ��ӵ�
	virtual eObjectType GetObjectType() const override;

	virtual void Explosived(class Bomb* a_refBomb)override;

};
