#include "lib/ListaDoble.hpp"

template <typename T>
class ListaOrdenada {
private:
  ListaDoble<T> lista;

public:
  ListaOrdenada();
  ~ListaOrdenada();
  ListaOrdenada<T>(const ListaOrdenada<T> &lista1);
  ListaOrdenada<T> &operator=(const ListaOrdenada<T> &lista1);
  void Agregar(T valor);
  void Eliminar(T valor);
  bool BuscarElemento(T valor) const;
  void Vaciar() const;
  bool EstaVacia() const;
  int ObtenerTam() const;
  void ImprimirAscendente() const;
  void ImprimirDescendente() const;
  ListaOrdenada<T> Mezclar(const ListaOrdenada<T> &lista1) const;
};

/****************************************************************************************************************/

template <typename T>
ListaOrdenada<T>::ListaOrdenada() {}

/****************************************************************************************************************/

template <typename T>
ListaOrdenada<T>::~ListaOrdenada() { lista.Vaciar(); }

/****************************************************************************************************************/

template <typename T>
ListaOrdenada<T>::ListaOrdenada(const ListaOrdenada<T> &lista1) {
  *this = lista1;
}

/****************************************************************************************************************/

template <typename T>
ListaOrdenada<T> &ListaOrdenada<T>::operator=(const ListaOrdenada<T> &lista1) {
  this->lista = lista1.lista;
}

/****************************************************************************************************************/

template <typename T>
void ListaOrdenada<T>::Eliminar(T valor) {
  int pos = lista.BuscarPos(valor);
  lista.EliminarDePos(pos);
}

/****************************************************************************************************************/

template <typename T>
bool ListaOrdenada<T>::BuscarElemento(T valor) const {
  return lista.SeEncuentraValor(valor);
}

/****************************************************************************************************************/

template <typename T>
void ListaOrdenada<T>::Vaciar() const {
  lista.Vaciar();
}

/****************************************************************************************************************/

template <typename T>
bool ListaOrdenada<T>::EstaVacia() const {
  return lista.EstaVacia();
}

/****************************************************************************************************************/

template <typename T>
int ListaOrdenada<T>::ObtenerTam() const {
  return lista.ObtenerTam();
}

/****************************************************************************************************************/

template <typename T>
void ListaOrdenada<T>::ImprimirAscendente() const {
  lista.Imprimir();
}

/****************************************************************************************************************/

template <typename T>
void ListaOrdenada<T>::ImprimirDescendente() const {
  lista.ImprimirEnReversa();
}

/****************************************************************************************************************/
