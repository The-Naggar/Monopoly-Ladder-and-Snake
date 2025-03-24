#include "NewGameAction.h"

#include "Grid.h"
#include "Cell.h"
#include "GameObject.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"
#include "Player.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"

NewGameAction::NewGameAction(ApplicationManager* pApp):Action(pApp)
{
}

void NewGameAction::ReadActionParameters()
{
}

void NewGameAction::Execute()
{
	
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Player* pPlayer;

	for (int i = 0; i < 4; i++)						//loop on the 4 players
	{
		pPlayer = pGrid->GetCurrentPlayer();        //getting each player

		pPlayer->ResetGame(pGrid);

		pGrid->AdvanceCurrentPlayer();				//getting next player

	}
	
	pGrid->ResetPlayer();							//gives turn back to first player
	pGrid->SetEndGame(false);						//returning end game to true
	CardTen::ResetCard();							//static func that return the owner of the cards and all card parameters to deafult
	CardEleven::ResetCard();
	CardTwelve::ResetCard();
	CardThirteen::ResetCard();
	pOut->PrintMessage("New Game! ,Have some Fun ");
}

NewGameAction::~NewGameAction()
{
}
