#ifndef COLUMN_H_
#define COLUMN_H_

#include <string>
#include "State.h"
#include "Card.h"

using std::string;
using KanbanBoardCard::Card;
using KanbanBoardState::State;

namespace KanbanBoardColumn {
	struct Column;

	/*
	 * Precondición: @state fue creado con la primitiva KanbanBoardState::CreateState.
	 * Postcondición: Devuelve una instancia válida de Column con con el titulo @title y con estado @state.
	 */
	Column* CreateColumn(string title, State* state);

	/*
	 * Precondición: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn.
	 * Postcondición: Devuelve el titulo de @column
	 */
	string GetTitle(Column* column);

	/*
	 * Precondición: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn.
	 * Postcondición: Cambia el titulo de @column por @title
	 */
	void SetTitle(Column* column, string title);

	/*
	 * Precondición:@column fue creado con la primitiva KanbanBoardColumn::CreateColumn.
	 * Postcondición: Devuelve el estado de @column
	 */
	State* GetState(Column* column);

	/*
	 * Precondicón: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn. @state fue creado con su primitiva creacional
	 * Postcondición:Cambia el estado de @column por @state
	 */
	void SetState(Column* column, State* state);

	/*
	 * Precondición: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn. @card fue creado con su primitiva creacional
	 * Postcondición: Si @card ya existe en @column no realiza acción, caso contrario agrega @card al final de la columna y le asigna a @card el estado de @column
	 */
	void AddCard(Column* column, Card* card);

	/*
	 * Precondición: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn. @card fue creado con su primitiva creacional
	 * Postcondición: Si @column tiene a @card, quita @card de la columna. Caso contrario no realiza ninguna acción
	 */
	void RemoveCard(Column* column, Card* card);

	/*
	 * Precondición: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn.
	 * Postcondición: Devuelve la cantidad de Cards que tiene @column
	 */
	int CountCards(Column* column);

	/*
	 * Precondición: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn.
	 * Postcondición: Devuelve la Card que se encuentra en la cima de @column. Si no hay Cards en @column devuelve NULL
	 */
	Card* GetTopPriorityCard(Column* column);

	/*
	 * Precondición: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn.
	 * Postcondición: Devuelve la Card que se encuentra abajo de toda la Columna. Si no hay Cards en @column devuelve NULL
	 */
	Card* GetLastPriorityCard(Column* column);

	/*
	 * Precondición: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn. @previousCard fue creado con su primitiva creacional
	 * Postcondición: Devuelve la card que sigue (con menor prioridad) a @previousCard. Es decir de la cima hacia abajo de la columna.
	 * Si @previousCard no existe o es la última Card o @column esta vacia, devuelve NULL
	 */
	Card* GetNextCard(Column* column, Card* previousCard);


	/*
	 * Precondición: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn.
	 * Postcondición: Devuelve la Card en @column que tiene el identificador @cardId. Si no existe devuelve NULL
	 */
	Card* GetCard(Column* column, string cardId);

	/*
	 * Precondición: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn.
	 * Postcondición: Aumenta la prioridad de la Card con el identificador @cardId subiendola hacia arriba de la cima. Si no existe no realiza ninguna acción
	 */
	void UpCardPriority(Column* column, string cardId);

	/*
	 * Precondición: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn.
	 * Postcondición: Sube la Card con el identificador @cardId a la suma de @column. Si no existe no realiza ninguna acción.
	 */
	
	void UpCardToTopPriority(Column* column, string cardId);

	/*
	 * Precondición: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn.
	 * Postcondición: Libera todos los recursos asociados a @column
	 */
	void DestroyColumn(Column* column);
}

#endif

