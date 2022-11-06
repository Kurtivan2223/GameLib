#include "AppManager.h"
#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>
#include <csignal>
#include <time.h>

time_t AppManager::m_InGameTimestamp;
time_t AppManager::m_NestRaidTimestamp;
struct PlayerInfo* Player = (struct PlayerInfo*)malloc(sizeof(PlayerInfo));

void AppManager::Initialize()
{
	auto hThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)AppManager::InitializeDiscordRichPresence, 0, 0, 0);
	SetThreadPriority(hThread, -1);
}

DWORD WINAPI AppManager::InitializeDiscordRichPresence()
{
	return 0;
}

void AppManager::UpdateGameState(GAME_STATE State)
{
	if (m_GameState != GAME_STATE::IN_GAME && State == GAME_STATE::IN_GAME)
		m_InGameTimestamp = time(nullptr);
	else if (Player->MapID == 10) //10 is just an e.g
		m_NestRaidTimestamp = time(nullptr);

	m_GameState = State;
}

std::string AppManager::getMapName(int MapID)
{
	switch (MapID)
	{
		//Im fucking lazy
	}
}