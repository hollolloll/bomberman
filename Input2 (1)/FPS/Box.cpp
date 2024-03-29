#include "pch.h"
#include "Box.h"

#include "GameManager.h"

Box::Box(int x, int y) : Object(x, y)
, m_Data{
		{ '1', '1', '1', '1', '1' },
		{ '1', ' ', ' ', ' ', '1' },
		{ '1', ' ', 'B', ' ', '1' },
		{ '1', ' ', ' ', ' ', '1' },
		{ '1', '1', '1', '1', '1' },
} {m_pNowAni = &m_Data; }

Box::~Box() { }

eObjectType Box::GetObjectType() const
{
	return eObjectType::Box;
}

bool Box::Explosived()
{
	GameMng()->DropItem(this);

	return true;
}
