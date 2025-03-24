#include "CardFour.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number (4 here)
}
void CardFour::ReadCardParameters(Grid* pGrid) {

}
void CardFour::EditCard(Grid* pGrid) {

}
CardFour::~CardFour(void)
{
}
void CardFour::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid, pPlayer); // Prints a message for reaching the card to the user
	ReadCardParameters(pGrid);	//	Reads card parameters (none in this card)
	Cell* pCurrentCell = pPlayer->GetCell();	// Get the players current cell
	CellPosition PlayerCell = pCurrentCell->GetCellPosition();	// Get the postionof the cell
	Snake* pSnake = pGrid->GetNextSnake(PlayerCell);	// Get a pointer of the next Snake
	if (pSnake)	//if there is not a next Snake the pointer becomes Null
	{
		CellPosition lCell = pSnake->GetPosition();
		pGrid->UpdatePlayerCell(pPlayer, lCell);	// Update the player position to the start of the Snake 
		pCurrentCell = pPlayer->GetCell();
		GameObject* pGameObj = pCurrentCell->GetGameObject();
		if (pGameObj)
		{
			pGameObj->Apply(pGrid, pPlayer);	//	Apply the Snake
		}
	}
}
void CardFour::MakeCopy(Grid* pGrid, GameObject* newObj)
{
	CardFour* pDataofCard = dynamic_cast<CardFour*>(newObj);
	Card* pCopyofCard = new CardFour(*pDataofCard);
	pGrid->SetClipboard(pCopyofCard);
}
void CardFour::Save(ofstream& OutFile, string type) {
	if (type == "CardType") //checks if the type is card if not don't save
	{
		int CardPos = CellPosition::GetCellNumFromPosition(position);	// We get the cell number of the card so we can store it
		OutFile << cardNumber << ' ' << CardPos << endl;	// We save the card number first then its cell number (No parameters to save in this card)
	}
}

void CardFour::Load(ifstream& Infile)
{
	string Input;
	getline(Infile, Input);	// We get the cell number of the card and set the position to the card we made in the LoadGirdAction
	int CellNum = stoi(Input);
	position = CellPosition::GetCellPositionFromNum(CellNum);
	//No Parameters to load for this card
}
