#include "lib/ListaDoble.hpp"
#include <iostream>

template <typename T> class ListaOrdenada {
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

template <typename T> ListaOrdenada<T>::ListaOrdenada() {}

template <typename T> ListaOrdenada<T>::~ListaOrdenada() { lista.Vaciar(); }

template <typename T>
ListaOrdenada<T>::ListaOrdenada(const ListaOrdenada<T> &lista1) {
  *this = lista1;
}

template <typename T>
ListaOrdenada<T> &ListaOrdenada<T>::operator=(const ListaOrdenada<T> &lista1) {
  this->lista = lista1.lista;
}
