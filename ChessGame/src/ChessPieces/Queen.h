#pragma once
#include "Rook.h"
#include "Bishop.h"
class Queen :
	public Rook,
	public Bishop
{
public:
	Queen(EColor color);

	virtual std::vector<Move> GetPossibleMoves() override;
};

