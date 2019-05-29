#include "ChessPiece.h"

ChessPiece::ChessPiece(EColor color) : m_color(color), m_movable(false)
{

}

void ChessPiece::Reset()
{
	m_movable = false;
}

EColor ChessPiece::GetColor() const
{
	return EColor();
}

void ChessPiece::SetMovable()
{
	m_movable = true;
}

bool ChessPiece::IsMoveable() const
{
	return m_movable;
}
