#include <iostream>
#include <vector>
#include "DyV.h"

using namespace std;

int main(){
	vector<int> a{1, 2, 3, 4, 5};
	vector<double> b{1.1, 1.2, 1.3, 1.4, 1.5};
	vector<char> c{'1', '2', '3', '4', '5'};

	int posicion;

	posicion = BusquedaBinaria(4, a, 0, a.size() - 1);

	if(posicion == -1){
		cout << "No se ha econtrado el elemento en el array (función int)\n";
	}
	else{
		cout << "El valor se encuentra en la posición: " << posicion << " (función int)\n";
	}

	posicion = BusquedaBinaria(1.3, b, 0, b.size() - 1);

	if(posicion == -1){
                cout << "No se ha econtrado el elemento en el array (función double)\n";
        }
        else{
                cout << "El valor se encuentra en la posición: " << posicion << " (función double)\n";
        }

	posicion = BusquedaBinaria('2', c, 0, c.size() - 1);

	if(posicion == -1){
                cout << "No se ha econtrado el elemento en el array (función char)\n";
        }
        else{
                cout << "El valor se encuentra en la posición: " << posicion << " (función char)\n";
        }


	return 0;
}
