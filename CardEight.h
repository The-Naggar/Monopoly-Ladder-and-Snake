#pragma once
#include "Card.h"
#include "Player.h"
#include "RollDiceAction.h"

class CardEight : public Card
{


public:
	CardEight(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // No parameters

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	// by decrementing the player's wallet by the walletAmount data member

	virtual void EditCard(Grid* pGrid);

	void MakeCopy(Grid* pGrid, GameObject* newObj);

	virtual void Save(ofstream& OutFile, string type);	// Save the parameters of CardThree

	virtual void Load(ifstream& Infile);	// Load the parameters of CardEight

	virtual ~CardEight(); // A Virtual Destructor
};
