#pragma once
class ObjectFactory
{
public:
	static class Object* make(eObjectType a_eType, int x, int y);
};

