#ifndef STATE_H_
#define STATE_H_

#include <string>

using std::string;

namespace KanbanBoardState {
	struct State;

	/*
	 * Precondición: ninguna
	 * Postcondición: Devuelve una instancia válida de State con con el nombre @name. Si @name es vacio establece como nombre de @state
	 * el valor "<Sin Nombre>"
	 */
	State* CreateState(string name);

	/*
	 * Precondición: @state fue creado con la primitiva KanbanBoardState::CreateState.
	 * Postcondición: Devuelve el nombre de @state
	 */
	string GetName(const State* state);

	/*
	 * Precondición: @state fue creada con la primitiva KanbanBoardState::DestroyState
	 * Postcondición: Libera todos los recursos asociados de @state
	 */
	void DestroyState(State* state);
}

#endif

