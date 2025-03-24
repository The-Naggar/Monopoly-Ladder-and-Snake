#include "CardEight.h"

CardEight::CardEight(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8; // set the inherited cardNumber data member with the card number (5 here)
}
void CardEight::ReadCardParameters(Grid* pGrid) {

}

void CardEight::EditCard(Grid* pGrid){

}

CardEight::~CardEight(void)
{
}
void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	ReadCardParameters(pGrid);
	
	pPlayer->SetFreezeRound(true);

}
void CardEight::MakeCopy(Grid* pGrid, GameObject* newObj)
{
	CardEight* pDataofCard = dynamic_cast<CardEight*>(newObj);
	Card* pCopyofCard = new CardEight(*pDataofCard);
	pGrid->SetClipboard(pCopyofCard);
}
void CardEight::Save(ofstream& OutFile, string type) 
{
	if (type == "CardType") 
	{
		int CardPos = CellPosition::GetCellNumFromPosition(position);
		OutFile << cardNumber << ' ' << CardPos << endl;
	}
}
void CardEight::Load(ifstream& Infile) 
{
	string Input;
	getline(Infile, Input);
	int CellNum = stoi(Input);
	position = CellPosition::GetCellPositionFromNum(CellNum);
}