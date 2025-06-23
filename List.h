namespace UndavLista {
	struct List;

	List* CreateEmptyList();

	// Consulta
	bool IsEmpty(const List* lista);
	int ContarItems(const List* lista);
	
	// Agregado
	void AgregarAlComienzo(List* lista, void* item);
	void AddToEnd(List* lista, void* item);
	void AgregarRango(List* lista, List* items);
	void AgregarRango(List* lista, void** items, int cantidadItems);

	// Quitar
	void Vaciar(List* lista);
	void QuitarPrimero(List* lista);
	void QuitarUltimo(List* lista);
	// Quitar un item intermedio

	namespace UndavIteradorLista {
		struct IteradorLista;
		IteradorLista* Begin(List* lista);
		bool End(IteradorLista* iterador);
		void* GetItem(IteradorLista* iterador);
		void Next(IteradorLista* iterador);
		void Destroy(IteradorLista* iterador);
	}


	void Destroy(List* lista);
}


