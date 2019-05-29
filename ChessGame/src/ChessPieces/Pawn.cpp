#include "Pawn.h"

Pawn::Pawn(EColor color)
	:ChessPiece(color)
{
	m_possibleMoves.push_back(std::make_pair(EDirection::Forward, EMoveType::Single));
	m_possibleMoves.push_back(std::make_pair(EDirection::Forward, EMoveType::Double));
}

std::vector<Move> Pawn::GetPossibleMoves()
{
	return m_possibleMoves;
}
