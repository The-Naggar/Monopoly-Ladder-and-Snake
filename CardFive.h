#pragma once
#include "Card.h"
#include "Player.h"


class CardFive : public Card
{


public:
	CardFive(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // No parameters

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFive on the passed Player
	// by moving the player with same rolled dice Num

	virtual void EditCard(Grid* pGrid);

	void MakeCopy(Grid* pGrid, GameObject* newObj);		//virtual func for copying card

	virtual void Save(ofstream& OutFile, string type);		// Save the parameters of CardFive

	virtual void Load(ifstream& Infile);	// Load the parameters of CardFive

	virtual ~CardFive(); // A Virtual Destructor
};
