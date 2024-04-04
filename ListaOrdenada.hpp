/**
 * @author Omar Pacheco
 * @author Denisse Antunez
 * @file ListaOrdenada.hpp
 * Archivo de cabecera que define una lista ordenada generíca
 */

#include "lib/ListaDoble.hpp"

/**
 * @class ListaOrdenada
 * @brief Implementa una lista ordenada
 *
 * Esta
 * clase permite agregar elementos de manera ascendente
 *
 * @tparam T Tipo de
 * dato de los elementos a guardar en la lista
 */
template <typename T> 
class ListaOrdenada {
private:
  ListaDoble<T> lista; ///< Lista doble para guardar elementos

public:
  /**
   * @brief Constructor por default
   */
  ListaOrdenada();

  /**
   * @brief Destructor por default
   */
  ~ListaOrdenada();

  /**
   * @brief Constructor de copias
   * @param lista ListaOrdenada de tipo T recibida por referencia
   */
  ListaOrdenada<T>(const ListaOrdenada<T> &lista1);

  /**
   * @brief Sobrecarga de operador de asignación
   * @param lista ListaOrdenada de tipo T recibida por referencia
   * @return ListaOrdenada por referencia
   */
  ListaOrdenada<T> &operator=(const ListaOrdenada<T> &lista1);

  /**
   * @brief Método para agregar elementos a la lista de forma
   * ordenada ascendentemente
   * @param valor Valor a agregar a la lista
   */
  void Agregar(T valor);

  /**
   * @brief Método para eliminar la primera ocurrencia de
   * un elemento de la lista con el valor dado
   * @param valor Valor a eliminar de la lista
   */
  void Eliminar(T valor);

  /**
   * @brief Método para buscar un elemento
   * @param valor Valor a buscar en la lista
   * @return Booleano que indica si existe o no el elemento
   * en la lista
   */
  bool BuscarElemento(T valor) const;

  /**
   * @brief Método para vaciar la lista
   */
  void Vaciar();

  /**
   * @brief Método saber si está vacía la lista
   * @return Booleano que indica si esta o no vacia la lista
   */
  bool EstaVacia() const;

  /**
   * @brief Método para obtener el tamaño de la lista
   * @return Tamaño de la lista
   */
  int ObtenerTam() const;

  /**
   * @brief Método para imprimir la lista de forma ascendente
   */
  void ImprimirAscendente() const;

  /**
   * @brief Método para imprimir la lista de forma descendente
   */
  void ImprimirDescendente() const;

  /**
   * @brief Método para mezclar dos listas
   *
   * Este método junta los elementos de la lista que llama al
   * método y los elementos de la lista recibida por parámetro,
   * y regresa una nueva lista ordenada con los elementos de
   * ambas listas
   *
   * @param lista Lista ordenada recibida por referencia
   * @return Lista ordenada con los valores de ambas listas
   */
  ListaOrdenada<T> Mezclar(const ListaOrdenada<T> &lista) const;
};

/****************************************************************************************************************/

template <typename T> 
ListaOrdenada<T>::ListaOrdenada() {}

/****************************************************************************************************************/

template <typename T> 
ListaOrdenada<T>::~ListaOrdenada() { 
  lista.Vaciar(); }

/****************************************************************************************************************/

template <typename T>
ListaOrdenada<T>::ListaOrdenada(const ListaOrdenada<T> &lista1) {
  *this = lista1;
}

/****************************************************************************************************************/

template <typename T>
ListaOrdenada<T> &ListaOrdenada<T>::operator=(const ListaOrdenada<T> &lista1) {
  this->lista = lista1.lista;
  return *this;
}

/****************************************************************************************************************/

template <typename T> 
void ListaOrdenada<T>::Agregar(T valor) {
  if (lista.EstaVacia())
    lista.AgregarAlInicio(valor);
  else {
    int pos;
    int tam = lista.ObtenerTam();
    for (pos = 0; pos < tam && lista[pos] < valor; pos++);
    lista.AgregarEnPos(valor, pos);
  }
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
void ListaOrdenada<T>::Vaciar() { lista.Vaciar(); }

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

template <typename T>
ListaOrdenada<T>
ListaOrdenada<T>::Mezclar(const ListaOrdenada<T> &lista1) const {
  ListaOrdenada<T> nuevaLista;
  nuevaLista = lista1;

  int tam = ObtenerTam();

  for (int i = 0; i < tam; ++i)
    nuevaLista.Agregar(lista.ObtenerEnPos(i));

  return nuevaLista;
}

/****************************************************************************************************************/
