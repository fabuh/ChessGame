#pragma once
#include "ChessPiece.h"
class King :
	public ChessPiece
{
public:
	King(EColor color);

	virtual std::vector<Move> GetPossibleMoves() override;
};

