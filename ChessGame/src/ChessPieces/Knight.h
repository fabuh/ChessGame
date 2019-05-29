#pragma once
#include "ChessPiece.h"
class Knight :
	public ChessPiece
{
public:
	Knight(EColor color);

	virtual std::vector<Move> GetPossibleMoves() override;
};

