#include <vector>
#include <ostream>
#include <cstdlib>
#include <ctime>

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
int Partition_Final(vector<val> &V, int ini, int fin){
        val x = V[fin];    // Variable "pivote"
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
void QuickSort_Final(vector<val> &V, int ini, int fin){
        if(ini < fin){
                int pivot = Partition_Final(V, ini, fin);
                QuickSort_Final(V, ini, pivot - 1);
                QuickSort_Final(V, pivot + 1, fin);
        }
}

template <typename val>
int Partition_Inicio(vector<val> &V, int ini, int fin){
        val x = V[ini];    // Variable "pivote"
	int i = fin;
	val aux;

	for(int j = fin; j >= ini + 1; j--){
		if(V[j] >= x){
			aux = V[i];
			V[i] = V[j];
			V[j] = aux;
			i = i - 1;
		}
	}
	aux = V[i];
	V[i] = V[ini];
	V[ini] = aux;
	return i;
}

template <typename val>
void QuickSort_Inicio(vector<val> &V, int ini, int fin){
        if(ini < fin){
                int pivot = Partition_Inicio(V, ini, fin);
                QuickSort_Inicio(V, ini, pivot - 1);
                QuickSort_Inicio(V, pivot + 1, fin);
        }
}

template <typename val>
int Partition_Medio(vector<val> &V, int ini, int fin){
        int medio = (ini + fin) / 2;
        val x = V[medio];    // Variable "pivote"
	int i = ini;
	int j = fin;
	val aux;

	while(i <= j){
	  while(V[i] < x){  // Encontrar 1r elemento >= que el pivote
	    i++;
	  }
	  while(V[j] > x){  // Encontrar 1r elemento <= que el pivote
	    j--;
	  }
	  if(i <= j){
	    aux = V[i];
	    V[i] = V[j];
	    V[j] = aux;
	    i++;
	    j--;
	  }
	}
	
	return i;
}

template <typename val>
void QuickSort_Medio(vector<val> &V, int ini, int fin){
        if(ini < fin){
                int pivot = Partition_Medio(V, ini, fin);
		if(ini < pivot - 1){
		  QuickSort_Medio(V, ini, pivot - 1);
		}
                if(pivot < fin){
		  QuickSort_Medio(V, pivot + 1, fin);
		}
        }
}

template <typename val>
int Partition_Random(vector<val> &V, int ini, int fin){
        int random = ini + rand() % (fin - ini + 1);
        val x = V[random];    // Variable "pivote"
	int i = ini;
	int j = fin;
	val aux;

	while(i <= j){
	  while(V[i] < x){  // Encontrar 1r elemento >= que el pivote
	    i++;
	  }
	  while(V[j] > x){  // Encontrar 1r elemento <= que el pivote
	    j--;
	  }
	  if(i <= j){
	    aux = V[i];
	    V[i] = V[j];
	    V[j] = aux;
	    i++;
	    j--;
	  }
	}
	
	return i;
}

template <typename val>
void QuickSort_Random(vector<val> &V, int ini, int fin){
        if(ini < fin){
                int pivot = Partition_Random(V, ini, fin);
		if(ini < pivot - 1){
		  QuickSort_Random(V, ini, pivot - 1);
		}
                if(pivot < fin){
		  QuickSort_Random(V, pivot, fin);
		}
        }
}

