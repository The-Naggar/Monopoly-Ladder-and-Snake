
#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();	
	// Read the endPos parameter

	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();


	///TODO: Make the needed validations on the read parameters



	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	if (!startPos.IsValidCell())
	{
		pGrid->PrintErrorMessage("Error : Wrong Cell , try again");
	}
	else {
		if (startPos.HCell() == endPos.HCell())
		{
			if (startPos.GetCellNum() != 99) {
				Snake* pSnake = new Snake(startPos, endPos);
				if (pSnake->GetEndPosition().IsValidCell())
				{

					// Add the card object to the GameObject of its Cell:
					if (!(pGrid->IsOverlapping(pSnake))) {
						bool added = pGrid->AddObjectToCell(pSnake);
						// if the GameObject cannot be added
						if (!added)
						{
							// Print an appropriate message
							pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
						}
					}
					else pGrid->PrintErrorMessage("The Snake is overlapping");
				}
				else
				{
					pGrid->PrintErrorMessage("Error : End Cell Can't be above Start cell");
				}
			}
			else
			{
				pGrid->PrintErrorMessage("You can't put a snake on the end cell");
			}
		}
		else
		{
		
			pGrid->PrintErrorMessage("Error : Choose two cells in the same coloumn please");
		}
	}
	// Create a Snake object with the parameters read from the user
	// Here, the Snake is created and added to the GameObject of its Cell, so we finished executing the AddSnakeAction

}
