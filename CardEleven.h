#pragma once

#include "Card.h"

class CardEleven : public Card
{
	// CardEleven Parameters:
	static int CardPrice;
	static int Fees;
	static bool IsBought;
	static int count; // number of cards starting from 0
	static bool IsFirstTime; // First time to apply the card
	static Player* Buyer; //same player for all cards 10 
	static bool FirstSave;
	static bool FirstLoad;
public:
	CardEleven(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardEleven which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardEleven on the passed Player
	// by decrementing the player's wallet by the walletAmount data member

	virtual void EditCard(Grid* pGrid);

	void MakeCopy(Grid* pGrid, GameObject* newObj);

	virtual void Save(ofstream& OutFile, string type);	// Save the parameters of CardEleven

	virtual void Load(ifstream& Infile);	// Load the parameters of CardEleven

	static void ResetCard();
	static void SetCount(int Newcount);
	static int GetCount();
	static void ResetFirstSave();	// Resets FirstSave which allows multiple saves

	static void ResetFirstLoad();	// Resets FirstLoad which allows multiple loads

	virtual ~CardEleven(); // A Virtual Destructor
};

