#pragma once

struct CharacterData
{
	float	fMoveSeepd;
	float	fBombTime;
	int		nBombPower;
	int		nBombCount;

	CharacterData();
};

struct Explosion
{
	int x;
	int y;
	int pow;

	Explosion(int _x, int _y, int _pow) : x(_x), y(_y), pow(_pow){}
};

struct CreateObj
{
	int x;
	int y;
	eObjectType type;
	CreateObj(int _x, int _y, eObjectType _type) : x(_x), y(_y), type(_type){}
};

class GameManager
{
#pragma region SINGLE_TON
private:
	static inline GameManager * m_pInstance = nullptr;
	GameManager();
	~GameManager();

	GameManager operator=(GameManager&) = delete;
	GameManager(GameManager&&) = delete;
	GameManager(const GameManager&) = delete;

public:

	static void CreateInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new GameManager();
			m_pInstance->Init();
		}
	}

	static GameManager * GetInstance()
	{
		return m_pInstance;
	}

	static void ReleaseInstance()
	{
		m_pInstance->Release();
		SAFE_DELETE(m_pInstance);
	}

#pragma endregion

public:
	enum
	{
		MaxLife = 3,		// 플레이어 라이프 수
		RoundTime = 90,		// 90초

		MoveSpeed = 10,		// 이동 속도
		BombTime = 2,		// 2초
		BombBasePower = 2,	// 2칸
		BombBaseCount = 1,	// 최초 폭탄 설치 갯수
	};

	enum class eGameState
	{
		None,

		Run,
		End,
	};

public:
	void Init();
	void Release();

	void GameInit();
	void StageStart();
	void StageEnd();

	void Update(float a_fDeltaTime);
	void Render();
	void PostRender();

	void ClearObject();
	class Object* CreateObject(eObjectType a_eObjType, int x, int y);

	// 상호작용
	void RemoveObject(class Object* a_pObj);
	void DropItem(class Object* a_pObj);
	void GetBombData(OUT class Bomb* a_refBomb) const;
	void ObtainItem(eItem a_eItem);
	void Die(class Object* a_refObj);
	class Object* AddBomb(int a_nPlayerX, int a_nPlayerY);
	void ResistExplosion(Object* a_refBomb,int x, int y, int Pow);
	bool MoveCheck(class Object* a_pMoveIgnoreObject = nullptr);
	void CheckExplosion(Object* a_refExplosion);
	void AddScore(int a_nScore);

private:

	void CreateExplosionRecursive(eDir a_eDir, int nBombX, int nBombY, int a_nRemainPow);
	bool FindObject_withPosition(eObjectType a_eObj, int x, int y);
private:

	// 오브젝트
	std::array<std::vector<class Object*>, (int)eObjectType::RenderDepthCount> m_arrObj;
	class Player* m_pPlayer = nullptr;

	// 스테이지 정보
	int m_nNowStage = 0;
	float m_fGameTime = 0;	// 스테이지별 남은 시간
	class MapData* m_refMap = nullptr;
	char** m_pMap = nullptr;

	// 데이터
	int m_nNowLife = 0;		// 플레이어 라이프
	int m_nScore = 0;		// 점수

	std::vector<class Object*> m_vcDelete;

	std::vector<CreateObj> m_vcCreate;

	// 폭발
	std::vector<Explosion> m_vcExplision;

	// 현재 플레이어 데이터
	CharacterData m_stPlayerData;

	// 게임 상태
	eGameState	m_eState = eGameState::None;

public:

	// 로그
	std::string m_sLog = "";
};



#define InitGameMng()		{GameManager::CreateInstance(); }
#define GameMng()			(GameManager::GetInstance())
#define ReleaseGameMng()	(GameManager::ReleaseInstance())
