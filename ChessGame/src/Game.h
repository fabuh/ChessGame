#pragma once
#include "ChessBoard.h"
class Game
{
public:
	Game();
	~Game();

	void Initilize();

	void Run();

	void WaitForImput();
	void Update();

private:
	bool m_endGame;
	EColor m_turn;

	std::pair<EEntryType, std::string> m_currentMove;

	Renderer* m_renderer;
	GameLog* m_log;
};

