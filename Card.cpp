#include "Card.h"


Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
}

void Card::SetCardNumber(int cnum)
{
	if (cnum <= 12 && cnum >= 1)
		cardNumber = cnum; // needs validation
	else
		cardNumber = -1;
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::SetCardPosition(CellPosition CardPos)
{
	
	position.SetHCell(CardPos.HCell());
	position.SetVCell(CardPos.VCell());
}

void Card::Draw(Output* pOut) const
{
	pOut->DrawCell(position, cardNumber);
	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"


}

void Card::MakeCopy(Grid* pGrid, GameObject* newObj)
{
}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::EditCard(Grid* pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes

}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click
	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

void Card::Save(ofstream& OutFile, string type) {

}

void Card::Load(ifstream& Infile) {

}

Card::~Card()
{
}
