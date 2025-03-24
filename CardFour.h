#pragma once
#include "Card.h"
#include "Snake.h"
class CardFour : public Card
{


public:
	CardFour(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount/

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	// by decrementing the player's wallet by the walletAmount data member

	virtual void EditCard(Grid* pGrid);

	void MakeCopy(Grid* pGrid, GameObject* newObj);

	virtual void Save(ofstream& OutFile, string type);	// Save the parameters of CardFour

	virtual void Load(ifstream& Infile);	// Load the parameters of CardFour

	virtual ~CardFour(); // A Virtual Destructor
};
