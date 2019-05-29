#include "Game.h"
#include "Renderer.h"
#include "GameLog.h"

Game::Game() : m_endGame(false), m_log(nullptr), m_renderer(nullptr)
{
}

Game::~Game()
{
}

void Game::Initilize()
{
}

void Game::Run()
{
	while (!m_endGame)
	{
		WaitForImput();
		Update();
		m_log->AddLog(m_currentMove.first, m_currentMove.second);
	}
}

void Game::WaitForImput()
{
}

void Game::Update()
{
	
}

int main()
{
	Game game;
	game.Initilize();

	game.Run();

	//do stuff?

	return 0;
}
