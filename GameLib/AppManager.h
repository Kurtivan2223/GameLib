#pragma once
#include <memory>
#include <Windows.h>
#include <time.h>

struct PlayerInfo
{
	std::string PlayerName;
	int PlayerLevel;
	int MapID;
};

//Defines the State of the Program
enum GAME_STATE : char
{
	LOADING = 0,
	LOGIN_SCREEN = 1,
	SERVER_SELECTION = 2,
	CHARACTER_SELECTION = 3,
	IN_GAME = 4
};

class AppManager
{
private:
	static time_t m_InGameTimestamp;
	static time_t m_NestRaidTimestamp;
	static GAME_STATE m_GameState;
	static DWORD WINAPI InitializeDiscordRichPresence();
public:
	static void Initialize();
	static void UpdateGameState(GAME_STATE State);
	static std::string getMapName(int MapID);
};