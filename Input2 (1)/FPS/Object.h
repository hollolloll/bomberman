#pragma once

class Object
{
public:
	Object(int _x, int _y);
	virtual ~Object();
	virtual eObjectType GetObjectType() const = 0;

	bool Update(float a_fDelta);
	void Render();
	void SetMap(char** a_refMap);
	void RenderClear();

	virtual void Init();
	virtual void Explosived(class Bomb* a_refBomb);
	virtual bool Interaction(class Player* a_refHero);

	inline void SetPos(int _x, int _y) { x = _x; y = _y; rt.x = _x; rt.y = _y; }
	inline bool IsCross(const Object& a_refObj)
	{
		return rt.IsCross(a_refObj.rt);
	}
	inline bool IsCross(Object* a_refObj)
	{
		assert((a_refObj != nullptr) && "arg error");
		return IsCross(*a_refObj);
	}

	virtual Rect GetRendertRect() const; // 그림용 좌표

protected:

	virtual void _PreUpdate(float a_fDelta); // 이전단계의 글자 지우기
	virtual bool _Update(float a_fDelta);

public:
	int x; // 맵의 타일에서의 위치
	int y;
	Rect rt; // 충돌처리용 좌표

protected:

	static RenderTile Empty;
	char**	m_refMap = nullptr;
	RenderTile*	m_pNowAni = nullptr;
};
