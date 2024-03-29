#include "pch.h"
#include "Bomb.h"

#include "GameManager.h"
#include "Ani.h"

Bomb::Bomb(int x, int y) : Object(x, y), m_pAni(new Ani())
{
	m_pAni->Resize(1);
	m_pAni->Add(0,
		{
		   {{"XXXXX"},
			{"XXXXX"},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{"xxxxx"},
			{"xxxxx"},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{"XXXXX"},
			{"XXXXX"},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{"xxxxx"},
			{"xxxxx"},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{" XXX "},
			{" XXX "},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{" xxx "},
			{" xxx "},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{"  X  "},
			{"  X  "},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{"  x  "},
			{"  x  "},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{"     "},
			{"  x  "},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{"     "},
			{"     "},
			{"|   |"},
			{"| B |"},
			{"#####"}},
		}
	);

	m_pAni->SetState(0);
	m_pNowAni = m_pAni->Get();
}
Bomb::~Bomb() 
{
	SAFE_DELETE(m_pAni);
}

eObjectType Bomb::GetObjectType() const
{
	return eObjectType::Bomb;
}

void Bomb::Init()
{
	GameMng()->GetBombData(OUT this);
}

bool Bomb::_Update(float a_fDelta)
{
	// �ִ�
	m_pAni->Update(a_fDelta);
	m_pNowAni = m_pAni->Get();

	// ����
	m_fLifeTime -= a_fDelta;
	if (m_fLifeTime <= 0.0f)
	{
		COORD c = rt.Center();
		GameMng()->ResistExplosion(this, rt.x, rt.y, m_nExplosiveRange);

		std::string s = "Explosion Pos : ";
		s += std::to_string(c.X);
		s += " /// ";
		s += std::to_string(c.Y);
		s += "\n";
		GameMng()->m_sLog += s;
		
		return true;
	}

	return false;
}

bool Bomb::Explosived()
{
	GameMng()->ResistExplosion(this, rt.x, rt.y, m_nExplosiveRange);

	return true;
	// Bomb!
}
