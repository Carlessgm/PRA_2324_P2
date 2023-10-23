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
