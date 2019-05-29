#include "Queen.h"

Queen::Queen(EColor color)
	:Rook(color),
	Bishop(color),
	ChessPiece(color)
{
}

std::vector<Move> Queen::GetPossibleMoves()
{
	return m_possibleMoves;
}
