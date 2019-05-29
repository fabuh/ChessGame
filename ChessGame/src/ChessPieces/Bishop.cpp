#include "Bishop.h"

Bishop::Bishop(EColor color)
	:ChessPiece(color)
{
	m_possibleMoves.push_back(std::make_pair(EDirection::ForwardLeft, EMoveType::Multiple));
	m_possibleMoves.push_back(std::make_pair(EDirection::ForwardRight, EMoveType::Multiple));
	m_possibleMoves.push_back(std::make_pair(EDirection::BackwardLeft, EMoveType::Multiple));
	m_possibleMoves.push_back(std::make_pair(EDirection::BackwardRight, EMoveType::Multiple));
}

std::vector<Move> Bishop::GetPossibleMoves()
{
	return m_possibleMoves;
}
