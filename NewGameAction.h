#pragma once
#include "Action.h"
class NewGameAction :public Action
{
public:

	NewGameAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); 

	virtual void Execute(); // resets every thing 



	virtual ~NewGameAction(); // Virtual Destructor

};