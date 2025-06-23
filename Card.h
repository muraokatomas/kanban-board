#ifndef CARD_H_
#define CARD_H_

#include <string>
#include "CardComment.h"
#include "State.h"

using std::string;
using KanbandBoardCardComment::CardComment;
using KanbanBoardState::State;

namespace KanbanBoardCard {
	struct Card;
	enum CardType { Story, Task, Bug, Epic };
	/*
	 * Precondici�n: ninguna
	 * Postcondici�n: Devuelve una instancia v�lida de Card con identificador @id y con el nombre @name, la cual
	 * ademas guarda la fecha y hora de creaci�n. Si @name es vacio establece como nombre de la @card
	 * el valor "<Sin Nombre>"
	 */
	Card* CreateCard(string id, string name, CardType type);

	/*
	 * Precondici�n: @card fue creado con la primitiva KanbanBoardCard::CreateCard. @comment fue creado con
	 * la primitiva KanbanBoardCardComment::CardComment.
	 * Postcondici�n: Agrega un nuevo comentario, @comment, en @card. El @comment es agregado como last comentario.
	 */
	void AddComment(Card* card, CardComment* comment);

	/*
	 * Precondici�n: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondici�n: Devuelve el comentario en la posici�n @commentPosition. Las posiciones comienzan en cero.
	 * Si no existe un comentario en la posici�n especificada en @commentPosition devuelve NULL
	 */
	CardComment* GetComment(Card* card, unsigned int commentPosition);

	/*
	 * Precondici�n: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondici�n: Devuelve la cantidad de comentarios que tiene @card
	 */
	unsigned int GetCommentCount(Card* card);

	/*
	 * Precondici�n: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondici�n: Devuelve el primer comentario de @card. Si no hay comentarios en @card devuelve NULL
	 */
	CardComment* GetFirstComment(Card* card);

	/*
	 * Precondici�n: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondici�n: Devuelve el �ltimo comentario de @card. Si no hay comentarios en @card devuelve NULL
	 */
	CardComment* GetLastComment(Card* card);

	/*
	 * Precondici�n: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondici�n: Devuelve el identificador de @card
	 */
	string GetId(Card* card);

	/*
	 * Precondici�n: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondici�n: Cambia el nombre de @card por @name
	 */
	void SetName(Card* card, string name);

	/*
	 * Precondici�n: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondici�n: Devuelve el nombre de @card
	 */
	string GetName(Card* card);

	/*
	 * Precondici�n: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondici�n: Cambia la descripci�n de @card por @description
	 */
	void SetDescription(Card* card, string description);

	void SetId(Card* card, string newId);

	/*
	 * Precondici�n: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondici�n: Obtiene la descripci�n de @card
	 */
	string GetDescription(Card* card);

	/*
	 * Precondici�n: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondici�n: Cambia el responsable asignado de @card por @assigned
	 */
	void SetAssigned(Card* card, string assigned);

	/*
	 * Precondici�n: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondici�n: Obtiene el responsable asignado de @card
	 */
	string GetAssigned(Card* card);

	/*
	 * Precondici�n: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondici�n: Obtiene la fecha y hora de creaci�n de @card en formato [dd/mm/aaaa HH:mm:ss]
	 */
	string GetCreationDate(Card* card);

	/*
	 * Precondici�n: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondici�n: Cambia el estado de @card por @state
	 */
	void SetState(Card* card, State* state);

	/*
	 * Precondici�n: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondici�n: Obtiene el estado de @card
	 */
	State* GetState(Card* card);

	/*
	 * Precondici�n: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondici�n: Libera todos los recursos asociados de @card
	 */
	void DestroyCard(Card* card);
}

#endif
