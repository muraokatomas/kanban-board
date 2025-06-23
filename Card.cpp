#include<iostream>
#include "CardComment.h"
#include "Card.h"
#include "List.h"
#include "State.h"
#include<string>
#include<ctime>

using namespace std;
using namespace KanbanBoardCard;
using namespace KanbandBoardCardComment;
using namespace UndavLista;
using namespace KanbanBoardState;



struct KanbanBoardCard::Card
{
	string id;
	string name;
	KanbanBoardCard::CardType type;
	List* comment;
	string description;
	string assigned;
	string creationDate;
	State* state;
};

string CreationDate();

KanbanBoardCard::Card* KanbanBoardCard::CreateCard(string id, string name, CardType type)
{
	Card* card = new Card;

	if (name.empty())
	{
		card->name = "Sin nombre.";
	}
	else
	{
		card->id = id;
		card->name = name;
		card->creationDate = CreationDate();
		card->comment = CreateEmptyList();
		card->description;
	}
	card->type = type;
	return card;
}

string CreationDate()
{
	time_t current_time;
	time(&current_time);
	tm current_date;
	localtime_s(&current_date, &current_time);

	char buffer[80];

	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &current_date);

	string creation_date(buffer);

	return creation_date;
}

void KanbanBoardCard::AddComment(Card* card, CardComment* comment)
{
	UndavLista::AddToEnd(card->comment, comment);
}

CardComment* KanbanBoardCard::GetComment(Card* card, unsigned int commentPosition)
{
	CardComment* comment = nullptr;
	UndavIteradorLista::IteradorLista* iterador = UndavIteradorLista::Begin(card->comment);
	unsigned int i = 0;

	while (iterador != NULL && i <= commentPosition)
	{
		if (i == commentPosition)
		{
			comment = (KanbandBoardCardComment::CardComment*)UndavIteradorLista::GetItem(iterador);
			break;
		}
		UndavIteradorLista::Next(iterador);
		i++;
	}
	UndavLista::UndavIteradorLista::Destroy(iterador);
	return comment;
}

unsigned int KanbanBoardCard::GetCommentCount(Card* card)
{
	int countComments = 0;
	UndavIteradorLista::IteradorLista* iterador = UndavIteradorLista::Begin(card->comment);
	while (!UndavIteradorLista::End(iterador))
	{
		countComments++;
		UndavIteradorLista::Next(iterador);
	}
	UndavIteradorLista::Destroy(iterador);
	return countComments;
}

KanbandBoardCardComment::CardComment* KanbanBoardCard::GetFirstComment(Card* card)
{
	KanbandBoardCardComment::CardComment* firstComment;

	if (card->comment != NULL)
	{
		firstComment = (CardComment*)UndavIteradorLista::Begin(card->comment);
	}
	else
	{
		firstComment = NULL;
	}
	return firstComment;
}

CardComment* KanbanBoardCard::GetLastComment(Card* card)
{
	KanbandBoardCardComment::CardComment* lastComment = nullptr;
	UndavIteradorLista::IteradorLista* iterador = UndavIteradorLista::Begin(card->comment);

	while (!UndavIteradorLista::End(iterador))
	{
		UndavIteradorLista::Next(iterador);
	}

	lastComment = (KanbandBoardCardComment::CardComment*)UndavIteradorLista::GetItem(iterador);
	UndavIteradorLista::Destroy(iterador);
	return lastComment;
}

string KanbanBoardCard::GetId(Card* card)
{
	return card->id;
}

string KanbanBoardCard::GetName(Card* card)
{
	return card->name;
}

void KanbanBoardCard::SetName(Card* card, string name)
{
	card->name = name;
}

void KanbanBoardCard::SetDescription(Card* card, string description)
{
	card->description = description;
}

string KanbanBoardCard::GetDescription(Card* card)
{
	return card->description;
}

void KanbanBoardCard::SetAssigned(Card* card, string assigned)
{
	card->assigned = assigned;
}

string KanbanBoardCard::GetAssigned(Card* card)
{
	return card->assigned;
}

string KanbanBoardCard::GetCreationDate(Card* card)
{
	return card->creationDate;
}

void KanbanBoardCard::SetId(Card* card, string newId)
{
	card->id = newId;
}

void KanbanBoardCard::SetState(Card* card, State* state)
{
	card->state = state;
}

void KanbanBoardCard::DestroyCard(Card* card)
{
	UndavLista::UndavIteradorLista::IteradorLista* iterador = UndavIteradorLista::Begin(card->comment);
	while (!UndavLista::UndavIteradorLista::End(iterador))
	{
		KanbandBoardCardComment::DestroyComment((KanbandBoardCardComment::CardComment*)UndavIteradorLista::GetItem(iterador));
		UndavLista::UndavIteradorLista::Next(iterador);
	}
	UndavLista::Destroy(card->comment);
	UndavLista::UndavIteradorLista::Destroy(iterador);
	delete card;
}