#include "List.h"
#include "CardComment.h"
#include "Card.h"
#include <iostream>

using namespace std;
using namespace KanbanBoardCard;
using namespace KanbandBoardCardComment;

struct Node 
{
	void* item;
	Node* next;
};

struct UndavLista::List 
{
	Node* first;
	Node* last;
	int cantidadItems;
};

Node* CreateLastNode(void* item);

// O(1)
UndavLista::List* UndavLista::CreateEmptyList()
{
	List* nuevaLista = new List;
	nuevaLista->first = NULL;// Asignacion destructiva
	nuevaLista->last = NULL;
	nuevaLista->cantidadItems = 0;
	return nuevaLista;
}

Node* CreateLastNode(void* item) 
{
	Node* nuevoNodo = new Node;
	nuevoNodo->item = item;
	nuevoNodo->next = NULL;
	return nuevoNodo;
}

bool UndavLista::IsEmpty(const List* lista) 
{	
	return lista->cantidadItems == 0;
}

// O(N) -> O(1)
void UndavLista::AddToEnd(List* lista, void* item)
{
	Node* nuevoUltimo = CreateLastNode(item);
	if (IsEmpty(lista)) 
	{
		lista->first = nuevoUltimo;
	}
	else 
	{
		lista->last->next = nuevoUltimo;
	}
	lista->last = nuevoUltimo;
	lista->cantidadItems++;
}

// O(1)
int UndavLista::ContarItems(const List* lista) 
{
	return lista->cantidadItems;
}

void UndavLista::Vaciar(List* lista) 
{
	Node* iterador = lista->first;
	Node* auxiliar;
	while (iterador != NULL) 
	{
		auxiliar = iterador;
		iterador = iterador->next;
		delete auxiliar;
	}

	lista->cantidadItems = 0;
	lista->first = lista->last = NULL;
}

void UndavLista::Destroy(List* lista) 
{
	Vaciar(lista);
	delete lista;
}

struct UndavLista::UndavIteradorLista::IteradorLista 
{
	Node* currentNode;
};

UndavLista::UndavIteradorLista::IteradorLista* UndavLista::UndavIteradorLista::Begin(List* lista) 
{	
	IteradorLista* nuevoIterador = new IteradorLista;
	nuevoIterador->currentNode = lista->first;

	return nuevoIterador;
}

bool UndavLista::UndavIteradorLista::End(IteradorLista* iterador) 
{	
	return iterador->currentNode == NULL;
}

void* UndavLista::UndavIteradorLista::GetItem(IteradorLista* iterador) 
{	
	return iterador->currentNode->item;
}

void UndavLista::UndavIteradorLista::Next(IteradorLista* iterador) 
{	
	iterador->currentNode = iterador->currentNode->next;
}

void UndavLista::UndavIteradorLista::Destroy(IteradorLista* iterador) 
{	
	delete iterador;
}