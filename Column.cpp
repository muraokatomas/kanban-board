#include<iostream>
#include "Card.h"
#include "Column.h"
#include "State.h"


using namespace std;
using namespace KanbanBoardCard;
using namespace KanbanBoardColumn;
using namespace KanbanBoardState;

struct CardColumnNode {
	CardColumnNode* next;
	CardColumnNode* previous;
	KanbanBoardCard::Card* item;
};

struct ListCardDoubleLinked {
	CardColumnNode* first;
	CardColumnNode* last;
	int length;
};

struct KanbanBoardColumn::Column
{
	ListCardDoubleLinked* cards;
	string title;
	KanbanBoardState::State* state;
};

ListCardDoubleLinked* CreateEmptyList();
void DestroyList(ListCardDoubleLinked* list);

CardColumnNode* CreateLastNode(KanbanBoardCard::Card* card, CardColumnNode* previous);


Column* KanbanBoardColumn::CreateColumn(string title, KanbanBoardState::State* state)
{
	KanbanBoardColumn::Column* column = new Column;
	column->title = title;
	column->state = state;
	column->cards = CreateEmptyList();
	return column;
}

ListCardDoubleLinked* CreateEmptyList()
{
	ListCardDoubleLinked* list = new ListCardDoubleLinked;
	list->first = NULL;
	list->last = NULL;
	list->length = 0;
	return list;
}

CardColumnNode* CreateLastNode(KanbanBoardCard::Card* card, CardColumnNode* previous)
{
	CardColumnNode* node = new CardColumnNode;
	node->item = card;
	node->next = NULL;
	node->previous = previous;
	return node;
}

string KanbanBoardColumn::GetTitle(KanbanBoardColumn::Column* column)
{
	return column->title;
}

void KanbanBoardColumn::SetTitle(KanbanBoardColumn::Column* column, string title)
{
	column->title = title;
}

KanbanBoardState::State* KanbanBoardColumn::GetState(KanbanBoardColumn::Column* column)
{
	return column->state;
}

void KanbanBoardColumn::SetState(KanbanBoardColumn::Column* column, KanbanBoardState::State* state)
{
	column->state = state;
}

void KanbanBoardColumn::AddCard(KanbanBoardColumn::Column* column, KanbanBoardCard::Card* card)
{
	CardColumnNode* newNode = CreateLastNode(card, column->cards->last); 
    KanbanBoardCard::SetState(card, column->state);
	
	if (column->cards->first == NULL)
	{
		column->cards->first = newNode;
	}
	else
	{
		column->cards->last->next = newNode;		
	}
	column->cards->last = newNode;
	column->cards->length++;
}

void KanbanBoardColumn::RemoveCard(KanbanBoardColumn::Column* column, KanbanBoardCard::Card* card)
{
	CardColumnNode* current = column->cards->first;

	while (current != nullptr && current->item != card) 
	{
		current = current->next;
	}

	if (current == nullptr) return;

	if (current->previous != nullptr) 
	{
		current->previous->next = current->next;
	}
	else 
	{
		column->cards->first = current->next;
	}

	if (current->next != nullptr) 
	{
		current->next->previous = current->previous;
	}
	else 
	{
		column->cards->last = current->previous;
	}

	delete current;
	column->cards->length--;
}

int KanbanBoardColumn::CountCards(KanbanBoardColumn::Column* column)
{
	return column->cards->length;
}

Card* KanbanBoardColumn::GetTopPriorityCard(KanbanBoardColumn::Column* column)
{
	if (column->cards->first != nullptr)
	{
		return column->cards->first->item;
	}
	return nullptr;
}

Card* KanbanBoardColumn::GetLastPriorityCard(KanbanBoardColumn::Column* column)
{
	if (column->cards->last!= nullptr)
	{
		return column->cards->last->item;
	}
	return nullptr;
}

Card* KanbanBoardColumn::GetNextCard(KanbanBoardColumn::Column* column, KanbanBoardCard::Card* previousCard)
{
	CardColumnNode* current = column->cards->first;

	while (current!= nullptr && current->item != previousCard)
	{
		current = current->next;
	}

	if (current!=nullptr && current->next!=nullptr)
	{
		return current->next->item;
	}
	return nullptr;
}

Card* KanbanBoardColumn::GetCard(KanbanBoardColumn::Column* column, string cardId)
{
	CardColumnNode* current = column->cards->first;

	while (current!=nullptr)
	{
		if (KanbanBoardCard::GetId(current->item) == cardId)
		{
			return current->item;
		}
		current = current->next;
	}
	return nullptr;
}

void KanbanBoardColumn::UpCardPriority(KanbanBoardColumn::Column* column, string cardId)
{
	
	if (column->cards->first == nullptr || KanbanBoardCard::GetId(column->cards->first->item) == cardId) return;

	CardColumnNode* current = column->cards->first;

	while (current != nullptr && KanbanBoardCard::GetId(current->item) != cardId) {
		current = current->next;
	}

	if (current == nullptr || current->previous == nullptr) return;

	CardColumnNode* prev = current->previous;

	// Update pointers
	prev->next = current->next;
	if (current->next != nullptr) {
		current->next->previous = prev;
	}
	else {
		column->cards->last = prev;
	}

	current->next = prev;
	current->previous = prev->previous;
	if (prev->previous != nullptr) {
		prev->previous->next = current;
	}
	else {
		column->cards->first = current;
	}
	prev->previous = current;
	
}

void KanbanBoardColumn::UpCardToTopPriority(Column* column, string cardId)
{
	if (column == nullptr || column->cards == nullptr || column->cards->first == nullptr) {
		return;
	}

	if (KanbanBoardCard::GetId(column->cards->first->item) == cardId) {
		return;
	}

	CardColumnNode* current = column->cards->first;

	while (current != nullptr && KanbanBoardCard::GetId(current->item) != cardId) {
		current = current->next;
	}

	if (current == nullptr) {
		return;
	}

	if (current->previous != nullptr) {
		current->previous->next = current->next;

		if (current->next != nullptr) {
			current->next->previous = current->previous;
		}
		else {
			column->cards->last = current->previous;
		}

		current->next = column->cards->first;
		column->cards->first->previous = current;
		column->cards->first = current;
		current->previous = nullptr;
	}
}

void DestroyList(ListCardDoubleLinked* list) {

	if (list == nullptr) return;
	CardColumnNode* current = list->first;
	while (current != nullptr) {
		CardColumnNode* next = current->next;
		delete current;
		current = next;
	}
	delete list;
}
void KanbanBoardColumn::DestroyColumn(KanbanBoardColumn::Column* column)
{
	if (column == nullptr) return;

	DestroyList(column->cards);
	delete column;
}