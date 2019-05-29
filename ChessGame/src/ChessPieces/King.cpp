#include "King.h"

King::King(EColor color)
	:ChessPiece(color)
{
	m_possibleMoves.push_back(std::make_pair(EDirection::Forward, EMoveType::Single));
	m_possibleMoves.push_back(std::make_pair(EDirection::Backward, EMoveType::Single));
	m_possibleMoves.push_back(std::make_pair(EDirection::Left, EMoveType::Single));
	m_possibleMoves.push_back(std::make_pair(EDirection::Right, EMoveType::Single));
	m_possibleMoves.push_back(std::make_pair(EDirection::ForwardLeft, EMoveType::Single));
	m_possibleMoves.push_back(std::make_pair(EDirection::ForwardRight, EMoveType::Single));
	m_possibleMoves.push_back(std::make_pair(EDirection::BackwardLeft, EMoveType::Single));
	m_possibleMoves.push_back(std::make_pair(EDirection::BackwardRight, EMoveType::Single));
	m_possibleMoves.push_back(std::make_pair(EDirection::Left, EMoveType::Castle));
	m_possibleMoves.push_back(std::make_pair(EDirection::Right, EMoveType::Castle));
}

std::vector<Move> King::GetPossibleMoves()
{
	return m_possibleMoves;
}
