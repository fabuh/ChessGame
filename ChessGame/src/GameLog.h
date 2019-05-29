#pragma once
#include <string>
enum EEntryType
{
	Move,
	Check,
	CheckMate,
	Count
};

struct GameLogEntry
{
	EEntryType m_type = EEntryType::Count;
	const std::string* m_message = nullptr;
public:
	GameLogEntry(EEntryType type = EEntryType::Count, const std::string* message = nullptr)
		: m_type(type), m_message(message) { }

	const GameLogEntry& operator=(const GameLogEntry& other)
	{
		if (this != &other)
		{
			this->m_message = other.m_message;
			this->m_type = other.m_type;
		}
	}
};

class GameLog
{
public:
	GameLog();
	~GameLog();

	void Read();
	void Write();

	void AddLog(EEntryType type, const std::string* message);

private:
	void Resize();

private:
	GameLogEntry* m_container;
	size_t m_size;
	size_t m_maxSize;
};