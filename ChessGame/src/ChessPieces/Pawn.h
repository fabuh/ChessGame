#pragma once
#include "ChessPiece.h"
class Pawn :
	public ChessPiece
{
public:
	Pawn(EColor color);

	virtual std::vector<Move> GetPossibleMoves() override;
};

