#include "CardEleven.h"

int CardEleven::CardPrice;
int CardEleven::Fees;
bool CardEleven::IsBought = false;
int CardEleven::count = 0;
bool CardEleven::IsFirstTime = true;
Player* CardEleven::Buyer = NULL;
bool CardEleven::FirstSave = true;
bool CardEleven::FirstLoad = true;
CardEleven::CardEleven(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 11;
	IsBought = false;
}

CardEleven::~CardEleven(void)
{
}

void CardEleven::ReadCardParameters(Grid* pGrid)
{

	// 1- Get a Pointer to the Input / Output Interfaces from the Grid

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	if (!count)
	{

		string msg = "New CardEleven added, Enter Card Price: ";
		pOut->PrintMessage(msg);
		CardPrice = pIn->GetInteger(pOut);
		while (CardPrice < 0)
		{
			pOut->PrintMessage("Why Negative? We should give you the money!! Try again: ");
			CardPrice = pIn->GetInteger(pOut);
		}
		msg = "Enter Fees to pay by passing players: ";
		pOut->PrintMessage(msg);
		Fees = pIn->GetInteger(pOut);
		while (Fees < 0)
		{
			pOut->PrintMessage("Why Negative? We should give them money?! Try again: ");
			Fees = pIn->GetInteger(pOut);
		}
	}
		count++;


	// 2- Clear the status bar

	pOut->ClearStatusBar();

}

void CardEleven::EditCard(Grid* pGrid) 
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	string msg = "Edit CardEleven, Enter new Card Price: ";
	pOut->PrintMessage(msg);
	CardPrice = pIn->GetInteger(pOut);
	msg = "Enter Fees to pay by passing players: ";
	pOut->PrintMessage(msg);
	Fees = pIn->GetInteger(pOut);

	pOut->ClearStatusBar();


}

void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	Card::Apply(pGrid, pPlayer);

	if (!IsBought && (pPlayer->GetWallet() >= CardPrice) && IsFirstTime)
	{
		pOut->PrintMessage("Would you like to buy the station? (y/n)");
		string answer = pIn->GetSrting(pOut);
		pOut->ClearStatusBar();

		while (!(answer == "y" || answer == "n"))
		{
			pOut->PrintMessage("Invalid answer, try again: ");
			answer = pIn->GetSrting(pOut);
			pOut->ClearStatusBar();
		}

		if (answer == "y")
		{
			IsBought = true;
			Buyer = pPlayer;
			pPlayer->SetWallet(pPlayer->GetWallet() - CardPrice);
			IsFirstTime = false;
		}

	}

	if (pPlayer != Buyer && Buyer != 0)
	{
		if (pPlayer->GetWallet() >= Fees)
		{
			pPlayer->SetWallet(pPlayer->GetWallet() - Fees);
			Buyer->SetWallet(Buyer->GetWallet() + Fees);
		}
		else
		{
			int valuetotake = pPlayer->GetWallet();
			pPlayer->SetWallet(0);
			Buyer->SetWallet(Buyer->GetWallet() + valuetotake);

		}
	}

}
void CardEleven::MakeCopy(Grid* pGrid, GameObject* newObj)
{
	CardEleven* pDataofCard = dynamic_cast<CardEleven*>(newObj);
	Card* pCopyofCard = new CardEleven(*pDataofCard);
	pGrid->SetClipboard(pCopyofCard);
}
void CardEleven::ResetCard()
{
	IsBought = false;
	count = 0;
	IsFirstTime = true;
	Buyer = NULL;
}

void CardEleven::Save(ofstream& OutFile, string type) 
{
	if (type == "CardType") // Checks if first save because we save the price and fees in the first one only
	{
		int CardPos = CellPosition::GetCellNumFromPosition(position);

		if (FirstSave) {
			OutFile << cardNumber << ' ' << CardPos << ' ' << CardPrice << ' ' << Fees << endl;
			FirstSave = false;
		}
		else {
			OutFile << cardNumber << ' ' << CardPos << endl;
		}
	}
}

void CardEleven::Load(ifstream& Infile)		// Checks if first load because we get the parameters only in the first time
{
	string Input;
	if (FirstLoad) 
	{
		getline(Infile, Input, ' ');
		int CellNum = stoi(Input);
		position = CellPosition::GetCellPositionFromNum(CellNum);
		getline(Infile, Input, ' ');
		CardPrice = stoi(Input);
		getline(Infile, Input);
		Fees = stoi(Input);
		FirstLoad = false;
	}
	else {
		getline(Infile, Input);
		int CellNum = stoi(Input);
		position = CellPosition::GetCellPositionFromNum(CellNum);
	}
}
void CardEleven::SetCount(int Newcount)
{
	count = Newcount;
}

int CardEleven::GetCount()
{
	return count;
}
void CardEleven::ResetFirstSave()
{
	FirstSave = true;
}

void CardEleven::ResetFirstLoad()
{
	FirstLoad = true;
}