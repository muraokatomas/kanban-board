#include<iostream>
#include<string>
#include "State.h"

using namespace std;
using namespace KanbanBoardState;

struct KanbanBoardState::State
{
	string name;
};

State* KanbanBoardState::CreateState(string name)
{
	State* state = new State;
	
	if (name.empty())
	{
		state->name = "Sin nombre.";
	}
	else
	{
		state->name = name;
	}

	return state;
}

string KanbanBoardState::GetName(const State* state)
{
	return state->name;
}

void KanbanBoardState::DestroyState(State* state)
{
	delete state;
}
