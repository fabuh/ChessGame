#include "Rook.h"

Rook::Rook(EColor color)
	:ChessPiece(color)
{
	m_possibleMoves.push_back(std::make_pair(EDirection::Forward, EMoveType::Multiple));
	m_possibleMoves.push_back(std::make_pair(EDirection::Backward, EMoveType::Multiple));
	m_possibleMoves.push_back(std::make_pair(EDirection::Left, EMoveType::Multiple));
	m_possibleMoves.push_back(std::make_pair(EDirection::Right, EMoveType::Multiple));
}

std::vector<Move> Rook::GetPossibleMoves()
{
	return m_possibleMoves;
}