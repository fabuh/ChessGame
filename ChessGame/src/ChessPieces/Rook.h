#pragma once
#include "ChessPiece.h"
class Rook :
	virtual public ChessPiece
{
public:
	Rook(EColor color);

	virtual std::vector<Move> GetPossibleMoves() override;
};

