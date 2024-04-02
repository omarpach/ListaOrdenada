#include "ListaOrdenada.hpp"
#include "lib/ListaDoble.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
  try {
    ListaOrdenada<int> listaOrdenada;
    ListaDoble<int> lista;
    srand(time(nullptr));
    for (int i = 0; i < 10; ++i) {
      int n = 1 + rand() % 9;
      listaOrdenada.Agregar(n);
      lista.AgregarAlInicio(n);
    }
    cout << "Lista: ";
    lista.Imprimir();
    cout << "Lista Ordenada: ";
    listaOrdenada.ImprimirAscendente();
    listaOrdenada.ImprimirDescendente();
  } catch (ListaDoble<int>::ListaVacia &exc) {
    cerr << "Error: " << exc.what() << endl;
  } catch(ListaDoble<int>::FueraDeRango &exc) {
    cerr << "Error: " << exc.what() << endl;
  } catch (const char* e) {
    cerr << "Error: " << e << endl;
  } catch (...) {
    cerr << "Ocurrio un error inesperado" << endl; // TODO: Poner acentos
  }
}
