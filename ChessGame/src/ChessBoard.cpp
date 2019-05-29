#include "ChessBoard.h"

#define TARGET(moveToTile) auto& target = m_board[moveToTile.row * sChessBoardSide + moveToTile.col];

ChessBoard::ChessBoard(ESide whiteSide) : m_pickedUp(nullptr)
{
	m_board = new ChessPiece*[sChessBoardSize];

	EColor upColor = whiteSide == Up ? White : Black;
	EColor downColor = whiteSide == Down ? White : Black;
}

ChessBoard::~ChessBoard()
{
}

void ChessBoard::Initialize()
{
	for (size_t i = 0; i < sChessBoardSize; i++)
	{
		m_board[i] = nullptr;
	}
	InitializePieceOfType<Pawn>();
	InitializePieceOfType<Knight>();
	InitializePieceOfType<Bishop>();
	InitializePieceOfType<Rook>();
	InitializePieceOfType<Queen>();
	InitializePieceOfType<King>();
}

void ChessBoard::Move(ChessBoardTile moveToTile)
{
	if (TileOutOfBorders(moveToTile) || !m_pickedUp) return;
	TARGET(moveToTile);
	if (PossibleMove(moveToTile) && target && CanMoveTo(*target))
	{
		target = m_pickedUp;
		m_pickedUp = nullptr;
	}
}

bool ChessBoard::CanMoveTo(const ChessPiece& target)
{
	if (target.GetColor() == m_pickedUp->GetColor())
	{
		return false;
	}
	return true;
}

void ChessBoard::PickUp(ChessBoardTile moveToTile)
{
	if (TileOutOfBorders(moveToTile)) return;
	TARGET(moveToTile);
	if (target && CanPickUp(*target))
	{
		m_pickedUp = target;
	}
}

bool ChessBoard::CanPickUp(const ChessPiece& target)
{
	if (target.GetColor() == m_pickedUp->GetColor())
	{
		return false;
	}
	return true;
}

void ChessBoard::Drop()
{
	m_pickedUp = nullptr;
}

bool ChessBoard::TileOutOfBorders(ChessBoardTile tile)
{
	if (tile.row < 0 || tile.row >= sChessBoardSide
		|| tile.col < 0 || tile.col >= sChessBoardSide)
	{
		return true;
	}
	return false;
}

bool ChessBoard::PossibleMove(ChessBoardTile tile)
{
	TARGET(tile);
	if (target && target->IsMoveable())
	{
		return true;
	}
	return false;
}