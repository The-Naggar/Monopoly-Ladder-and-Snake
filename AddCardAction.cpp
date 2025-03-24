#include "AddCardAction.h"
#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp) 
{	// Initializes the pManager pointer of Action with the passed pointer

	cardNumber = -1; // Initialize cardNumber to avoid a compilation warning
	
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters() 
{	

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	// 2- Read the "cardNumber" parameter and set its data member
	pOut->PrintMessage("Enter the cardNumber: ");
	int inputCardNumber = pIn->GetInteger(pOut);

	if (inputCardNumber > 0 && inputCardNumber <= 13)
	{
		cardNumber = inputCardNumber;

		// 3- Read the "cardPosition" parameter (its cell position) and set its data member
		pOut->PrintMessage("Click on the cell position of your new Card, please! ");
		cardPosition = pIn->GetCellClicked();
	}
	else
	{
		cardNumber = -1;
		pGrid->PrintErrorMessage("Invalid Cell Number! There is no such card. Click to continue.");
	}
	// ^^^4- Needed validations on the read parameters^^^^

	// 5- Clear status bar
	pOut->ClearStatusBar();

}

void AddCardAction::Execute() 
{

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();

	if (cardPosition.IsValidCell() && cardPosition.GetCellNum() != 1 && cardPosition.GetCellNum() != 99)
	{


		// 2- Switch case on cardNumber data member and create the appropriate card object type
		Card* pCard = NULL; // will point to the card object type
		switch (cardNumber)
		{
		case 1:
			pCard = new CardOne(cardPosition);
			break;
		case 2:
			pCard = new CardTwo(cardPosition);
			break;
		case 3:
			pCard = new CardThree(cardPosition);
			break;
		case 4:
			pCard = new CardFour(cardPosition);
			break;
		case 5:
			pCard = new CardFive(cardPosition);
			break;
		case 6:
			pCard = new CardSix(cardPosition);
			break;
		case 7:
			pCard = new CardSeven(cardPosition);
			break;
		case 8:
			pCard = new CardEight(cardPosition);
			break;
		case 9:
			pCard = new CardNine(cardPosition);
			break;
		case 10:
			pCard = new CardTen(cardPosition);
			break;
		case 11:
			pCard = new CardEleven(cardPosition);
			break;
		case 12:
			pCard = new CardTwelve(cardPosition);
			break;
		case 13:
			pCard = new CardThirteen(cardPosition);
			break;
		default:
			pCard = nullptr;
			break;

		}

		// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
		if (pCard)
		{
			// A- We get a pointer to the Grid from the ApplicationManager
			Grid* pGrid = pManager->GetGrid();

			// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
			pCard->ReadCardParameters(pGrid);

			// C- Add the card object to the GameObject of its Cell:
			bool added = pGrid->AddObjectToCell(pCard);

			// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
			if (!added)
			{
				pGrid->PrintErrorMessage("Card can't be added to the Cell, Click to continue.");
			}

		}
	}

	else   // Handling some validations with the user.
	{
		if (cardNumber != -1)
		{
			Grid* pGrid = pManager->GetGrid();

			if (cardPosition.GetCellNum() == 1)
			{
				pGrid->PrintErrorMessage("You can't add a card in cellNumber 1. Life is not that easy!");
			}

			if (cardPosition.GetCellNum() == 99)
			{
				pGrid->PrintErrorMessage("You can't add a card in cellNumber 99. Game would be already over!");
			}
			
			if (!cardPosition.IsValidCell())
			{
				pGrid->PrintErrorMessage("The Grid is 90% of the game window, however you clicked outside the grid?!!");
			}
		}

	}
	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}
