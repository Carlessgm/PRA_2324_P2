#include <vector>
#include <ostream>

using namespace std;

template <typename val>
int BusquedaBinaria(val X, vector<val> V, int ini, int fin){
	if(ini > fin){
		return -1;
	}

	int medio = (ini + fin) / 2;

	if(V[medio] == X){
		return medio;
	}
	else if(V[medio] > X){
		return BusquedaBinaria(X, V, ini, medio - 1);
	}
	else{
		return BusquedaBinaria(X, V, medio + 1, fin);
	}
}

template <typename val>
int BusquedaBinaria_INV(val X, vector<val> V, int ini, int fin){
	if(ini > fin){
		return -1;
	}

	int medio = (ini + fin) / 2;

	if(V[medio] == X){
		return medio;
	}
	else if(V[medio] < X){
		return BusquedaBinaria_INV(X, V, ini, medio - 1);
	}
	else{
		return BusquedaBinaria_INV(X, V, medio + 1, fin);
	}
}

template <typename val>
int Partition(vector<val> &V, int ini, int fin){
	val x = V[fin];
	int i = ini;
	val aux;

	for(int j = ini; j <= fin - 1; j++){
		if(V[j] <= x){
			aux = V[i];
			V[i] = V[j];
			V[j] = aux;
			i = i + 1;
		}
	}
	aux = V[i];
	V[i] = V[fin];
	V[fin] = aux;
	return i;
}

template <typename val>
void QuickSort(vector<val> &V, int ini, int fin){
        if(ini < fin){
                int pivot = Partition(V, ini, fin);
                QuickSort(V, ini, pivot - 1);
                QuickSort(V, pivot + 1, fin);
        }
}

