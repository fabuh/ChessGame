#pragma once

#include <utility>
#include <vector>

enum EDirection
{
	Forward,
	Backward,
	Left,
	Right,
	ForwardLeft,
	ForwardRight,
	BackwardLeft,
	BackwardRight,
	Count
};

enum EMoveType
{
	Single,
	Double,
	Multiple,
	KnightMove,
	Castle,
	Count
};

enum EColor
{
	White,
	Black,
	Count
};

typedef std::pair<EDirection, EMoveType> Move;

class ChessPiece
{
public:
	ChessPiece(EColor color = EColor::Count);

	void Reset();

	EColor GetColor() const;
	
	void SetMovable();
	bool IsMoveable() const;
	
	virtual std::vector<Move> GetPossibleMoves() = 0;

protected:
	static std::vector<Move> m_possibleMoves;

private:
	EColor m_color;
	bool m_movable;
};

