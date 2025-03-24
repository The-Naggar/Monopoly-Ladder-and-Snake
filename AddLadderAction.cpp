#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"


AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer

}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();
	///TODO: Make the needed validations on the read parameters


	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	ReadActionParameters();
	if (!endPos.IsValidCell() )
	{
		pGrid->PrintErrorMessage("Invalid end Cell...");
	}
	else
	{
		if (startPos.HCell() == endPos.HCell())
		{
			if (startPos.GetCellNum() != 1) {
				Ladder* pLadder = new Ladder(startPos, endPos);
				if (pLadder->GetEndPosition().IsValidCell())
				{

					bool added = false;
					// Add the card object to the GameObject of its Cell:
					if (!(pGrid->IsOverlapping(pLadder))) {
						added = pGrid->AddObjectToCell(pLadder);

						if (!added)
						{
							// Print an appropriate message
							pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
						}
					}
					else {
						pGrid->PrintErrorMessage("Ladder is overlapping");
					}
				}
				else
				{
					pGrid->PrintErrorMessage("Error : Start Cell can't be above End cell ");
				}
			}
			else {
				pGrid->PrintErrorMessage("The ladder cannot be on the start cell ");
			}
		}
		else
		{
			pGrid->PrintErrorMessage("Error : Choose two cells in the same coloumn please");
		}
	}
	// Create a Ladder object with the parameters read from the user
	// if the GameObject cannot be added
	
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
