#include "GameLog.h"

GameLog::GameLog() : m_size(0), m_maxSize(2)
{
	m_container = new GameLogEntry[m_maxSize];
}

void GameLog::Read()
{

}

void GameLog::Write()
{

}

GameLog::~GameLog()
{
	delete[] m_container;
}

void GameLog::AddLog(EEntryType type, const std::string* message)
{
	if (m_size == m_maxSize)
	{
		Resize();
	}
	m_container[m_size++] = GameLogEntry(type, message);
}

void GameLog::Resize()
{
	m_maxSize *= 2;
	GameLogEntry* temp = new GameLogEntry[m_size];
	for (size_t i = 0; i < m_size; i++)
	{
		temp[i] = m_container[i];
	}
	delete[] m_container;
	m_container = temp;
}
