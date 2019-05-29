#pragma once
#include "ChessPiece.h"
class Bishop :
	virtual public ChessPiece
{
public:
	Bishop(EColor color);

	virtual std::vector<Move> GetPossibleMoves() override;
};

