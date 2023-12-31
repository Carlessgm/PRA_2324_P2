#include <iostream>
#include <vector>
#include "DyV.h"
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	cout << "- Vectores ordenados ascendentemente - BusquedaBinaria\n\n";
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

	cout << "\n\n- Vectores ordenados descendentemente - BusquedaBinaria_INV\n\n";

	vector<int> d{5, 4, 3, 2, 1};
	vector<double> e{1.5, 1.4, 1.3, 1.2, 1.1};
	vector<char> f{'5', '4', '3', '2', '1'};

	posicion = BusquedaBinaria_INV(4, d, 0, d.size() - 1);

	if(posicion == -1){
		cout << "No se ha econtrado el elemento en el array (función int)\n";
	}
	else{
		cout << "El valor se encuentra en la posición: " << posicion << " (función int)\n";
	}

	posicion = BusquedaBinaria_INV(1.1, e, 0, e.size() - 1);

	if(posicion == -1){
                cout << "No se ha econtrado el elemento en el array (función double)\n";
        }
        else{
                cout << "El valor se encuentra en la posición: " << posicion << " (función double)\n";
        }

	posicion = BusquedaBinaria_INV('5', f, 0, f.size() - 1);

	if(posicion == -1){
                cout << "No se ha econtrado el elemento en el array (función char)\n";
        }
        else{
                cout << "El valor se encuentra en la posición: " << posicion << " (función char)\n";
        }

	cout << "\n\n- Vectores desordenados - QuickSort\n\n";

        vector<int> g{1, 4, 3, 5, 2};
        vector<double> h{1.2, 1.3, 1.1, 1.5, 1.4};
        vector<char> i{'2', '5', '6', '1', '3'};
	vector<int> j{7, 4, 8, 2, 1};
	int aux;

	auto start_Final = chrono::system_clock::now();
	QuickSort_Final(g, 0, g.size() - 1);
	auto end_Final = chrono::system_clock::now();
	
	cout << "[";
	for(aux = 0; aux < g.size(); aux++){
		cout << g[aux];
		if(aux == g.size() - 1)
			cout << "] (int)\n";
		else
			cout << ", ";
	}
	
	chrono::duration<float, milli> duration_Final = end_Final - start_Final;
	cout << "Tiempo (Pivote = Final vector): " << duration_Final.count() << "s\n\n";

	auto start_Inicio = chrono::system_clock::now();
	QuickSort_Inicio(h, 0, h.size() - 1);
	auto end_Inicio = chrono::system_clock::now();

        cout << "[";
        for(aux = 0; aux < h.size(); aux++){
                cout << h[aux];
                if(aux == h.size() - 1)
                        cout << "] (double)\n";
                else
                        cout << ", ";
        }
	chrono::duration<float, milli> duration_Inicio = end_Inicio - start_Inicio;
        cout << "Tiempo (Pivote = Inicio Vector): " << duration_Inicio.count() << "s\n\n";

	auto start_Medio = chrono::system_clock::now();
	QuickSort_Medio(i, 0, i.size() - 1);
	auto end_Medio = chrono::system_clock::now();

        cout << "[";
        for(aux = 0; aux < i.size(); aux++){
                cout << i[aux];
                if(aux == i.size() - 1)
                        cout << "] (char)\n";
                else
                        cout << ", ";
        }
	chrono::duration<float, milli> duration_Medio = end_Medio - start_Medio;
        cout << "Tiempo (Pivote = Medio Vector): " << duration_Medio.count() << "s\n\n";

	srand(time(0));
	auto start_Random = chrono::system_clock::now();
        QuickSort_Random(j, 0, j.size() - 1);
        auto end_Random = chrono::system_clock::now();

        cout << "[";
        for(aux = 0; aux < j.size(); aux++){
                cout << j[aux];
                if(aux == j.size() - 1)
                        cout << "] (int)\n";
                else
                        cout << ", ";
        }

        chrono::duration<float, milli> duration_Random = end_Random - start_Random;
        cout << "Tiempo (Pivote = Pos. Random vector): " << duration_Random.count() << "s\n\n";

	return 0;
}
