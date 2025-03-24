#include "CardFive.h"

CardFive::CardFive(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (5 here)
}
void CardFive::ReadCardParameters(Grid* pGrid) {

}
void CardFive::EditCard(Grid* pGrid) {

}
CardFive::~CardFive()
{
}
void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	int OldDiceNUM = pPlayer->getRolledNum();				//getting player dice num
	Cell* pCell=pPlayer->GetCell();							//player's cell
	CellPosition OldPos=pCell->GetCellPosition();			//player's pos
	int NewCellNUM = OldPos.GetCellNumFromPosition(OldPos);	//player's cell num
	NewCellNUM = NewCellNUM + OldDiceNUM;					//making the new cell num
	CellPosition NewPos;
	NewPos=CellPosition::GetCellPositionFromNum(NewCellNUM);	//making new pos
	pGrid->UpdatePlayerCell(pPlayer, NewPos);				//getting the player to the new cell


	GameObject* pGameObj = pGrid->GetGameObject(NewPos);
	if (pGameObj)
	{
		pGameObj->Apply(pGrid, pPlayer);
	}
}
void CardFive::MakeCopy(Grid* pGrid, GameObject* newObj)
{
	CardFive* pDataofCard = dynamic_cast<CardFive*>(newObj);//getting card data to copy them
	Card* pCopyofCard = new CardFive(*pDataofCard);			//making new copy of the card to put in the paste pos
	pGrid->SetClipboard(pCopyofCard);						//putting the new object in the clipboard
}
void CardFive::Save(ofstream& OutFile, string type) 
{
	if (type == "CardType") 
	{
		int CardPos = CellPosition::GetCellNumFromPosition(position);
		OutFile << cardNumber << ' ' << CardPos << endl;
	}
}

void CardFive::Load(ifstream& Infile) 
{
	string Input;
	getline(Infile, Input);
	int CellNum = stoi(Input);
	position = CellPosition::GetCellPositionFromNum(CellNum);
}