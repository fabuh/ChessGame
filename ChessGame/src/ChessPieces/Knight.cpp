#include "Knight.h"

Knight::Knight(EColor color)
	:ChessPiece(color)
{
	m_possibleMoves.push_back(std::make_pair(EDirection::Forward, EMoveType::KnightMove));
	m_possibleMoves.push_back(std::make_pair(EDirection::Backward, EMoveType::KnightMove));
	m_possibleMoves.push_back(std::make_pair(EDirection::Left, EMoveType::KnightMove));
	m_possibleMoves.push_back(std::make_pair(EDirection::Right, EMoveType::KnightMove));
}

std::vector<Move> Knight::GetPossibleMoves()
{
	return m_possibleMoves;
}