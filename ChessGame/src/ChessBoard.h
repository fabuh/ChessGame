#pragma once

#include "ChessPieces/Pawn.h"
#include "ChessPieces/Knight.h"
#include "ChessPieces/Bishop.h"
#include "ChessPieces/Rook.h"
#include "ChessPieces/Queen.h"
#include "ChessPieces/King.h"

enum ESide
{
	Up,
	Down,
	Count
};

struct ChessBoardTile
{
	int row = 0;
	int col = 0;
};

static size_t sChessBoardSide = 8;
static size_t sChessBoardSize = sChessBoardSide * sChessBoardSide;

class ChessBoard
{
public:
	ChessBoard(ESide whiteSide);
	~ChessBoard();

	void Initialize();

	void Move(ChessBoardTile moveToTile);
	bool CanMoveTo(const ChessPiece& target);

	void PickUp(ChessBoardTile moveToTile);
	bool CanPickUp(const ChessPiece& target);

	void Drop();
private:
	bool TileOutOfBorders(ChessBoardTile tile);
	bool PossibleMove(ChessBoardTile tile);

private:
	template <typename PieceType>
	void InitializePieceOfType();

private:
	ChessPiece** m_board;
	ChessPiece* m_pickedUp;
	EColor m_upColor;
	EColor m_downColor;
};

template <typename PieceType>
void ChessBoard::InitializePieceOfType()
{
	if (std::is_same<PieceType, Pawn>)
	{
		for (int i = 0; i < sChessBoardSide; ++i)
		{
			m_board[1 * sChessBoardSide + i] = new Pawn(m_upColor);
			m_board[(sChessBoardSide - 2) * sChessBoardSide + i] = new Pawn(m_downColor);
		}
	}
	else if (std::is_same<PieceType, Rook>)
	{
		m_board[0] = new Rook(m_upColor);
		m_board[sChessBoardSide - 1] = new Rook(m_upColor);
		m_board[(sChessBoardSide - 1) * sChessBoardSide + 0] = new Rook(m_downColor);
		m_board[(sChessBoardSide - 1) * sChessBoardSide + sChessBoardSide - 1] = new Rook(m_downColor);
	}
	else if (std::is_same<PieceType, Knight>)
	{
		m_board[1] = new Knight(m_upColor);
		m_board[sChessBoardSide - 2] = new Knight(m_upColor);
		m_board[(sChessBoardSide - 1) * sChessBoardSide + 1] = new Knight(m_downColor);
		m_board[(sChessBoardSide - 1) * sChessBoardSide + sChessBoardSide - 2] = new Knight(m_downColor);
	}
	else if (std::is_same<PieceType, Bishop>)
	{
		m_board[2] = new Bishop(m_upColor);
		m_board[sChessBoardSide - 3] = new Bishop(m_upColor);
		m_board[(sChessBoardSide - 1) * sChessBoardSide + 2] = new Bishop(m_downColor);
		m_board[(sChessBoardSide - 1) * sChessBoardSide + sChessBoardSide - 3] = new Bishop(m_downColor);
	}
	else if (std::is_same<PieceType, Queen>)
	{
		if(m_upColor == White)
		{
			m_board[4] = new Queen(m_upColor);
			m_board[sChessBoardSide - 3] = new Queen(m_upColor);
		}
		else
		{
			m_board[3] = new Queen(m_upColor);
			m_board[sChessBoardSide - 4] = new Queen(m_upColor);
		}
	}
	if (std::is_same<PieceType, King>)
	{
		if (m_upColor == White)
		{
			m_board[3] = new Queen(m_upColor);
			m_board[sChessBoardSide - 4] = new Queen(m_upColor);
		}
		else
		{
			m_board[4] = new Queen(m_upColor);
			m_board[sChessBoardSide - 3] = new Queen(m_upColor);
		}
	}
}
