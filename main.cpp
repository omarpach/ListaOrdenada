#include "ListaOrdenada.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
  try {
    cout << "------------------Pruebas de lista ordenada------------------\n\n";

    ListaOrdenada<int> lista1;
    ListaOrdenada<int> lista2;
    ListaOrdenada<int> listaMezclada;

    srand(time(nullptr));

    for (int i = 0; i < 10; ++i) {
      int n = 1 + rand() % 9;
      int x = 1 + rand() % 9;
      lista1.Agregar(n);
      lista2.Agregar(x);
    }

    cout << "Lista 1 Ordenada Ascendentemente: ";
    lista1.ImprimirAscendente();
    cout << endl;

    cout << "Lista  1 Ordenada Descendentemente: ";
    lista1.ImprimirDescendente();
    cout << endl;

    cout << "Lista 2 Ordenada Ascendentemente: ";
    lista2.ImprimirAscendente();
    cout << endl;

    cout << "Se encuentra elemento 2 en la lista 1? " << boolalpha << lista1.BuscarElemento(2) << endl;

    cout << "Se encuentra vacia la lista 2? " << boolalpha << lista2.EstaVacia() << endl;

    cout << "Tamaño lista 1: " << lista1.ObtenerTam() << endl;

    listaMezclada = lista1.Mezclar(lista2);
    cout << "Listas 1 y 2 mezcladas: ";
    listaMezclada.ImprimirAscendente();
    cout << endl;

    cout << "Vaciando lista 1..." << endl;
    lista1.Vaciar();
    lista1.ImprimirAscendente();
    cout << endl;


  } catch (ListaDoble<int>::ListaVacia &exc) {
    cerr << "Error: " << exc.what() << endl;
  } catch(ListaDoble<int>::FueraDeRango &exc) {
    cerr << "Error: " << exc.what() << endl;
  } catch (const char* e) {
    cerr << "Error: " << e << endl;
  } catch (...) {
    cerr << "Ocurrio un error inesperado" << endl; // TODO: Poner acentos, letra ñ y ¿
  }
}
