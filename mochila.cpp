#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> mochila(vector <int> p, vector<int> b, int M, int n){
	int T[n + 1][M + 1];
	int i, j;

	for(j = 0; j < M + 1; j++){		//Fila 0
		T[0][j] = 0;
	}
	for(i = 1; i < n + 1; i++){		//Columna 0
		T[i][0] = 0;
	}

	for(i = 1; i < n + 1; i++){
		for(j = 1; j < M + 1; j++){
			if(p[i - 1] > j){
				T[i][j] = T[i - 1][j];
			}
			else{
				T[i][j] = max(T[i - 1][j], T[i - 1][j - p[i - 1]] + b[i - 1]);
			}
		}
	}

	for(i = 0; i < n + 1; i++){
		for(j = 0; j < M + 1; j++){
			cout << T[i][j] << " ";
		}
		cout << "\n";
	}

	vector<int> Sol(n, 0);         //Vector tamaño "n" inicializado a 0
	i = n;
	j = M;

	while(i != 0 && j != 0){
	  if(i == 0 || T[i][j] > T[i - 1][j]){
	    Sol[i - 1] = 1;
	    j = j - p[i - 1];
	  }
	    i = i - 1;
	}
	
	return Sol;
}

int main(){
        vector<int> p{9, 6, 5};	 	//Vector pesos
        vector<int> b{38, 40, 24};	//Vector beneficios
	int M = 15;			//Peso máximo

	vector<int> Sol = mochila(p, b, M, p.size());
	
	cout << "\nLa mejor combinación de objetos (peso máximo mochila: " << M << ") es:\n";
	int peso_total = 0, beneficio_total = 0;
	
	for(int i = 0; i < Sol.size(); i++){
	  if(Sol[i] == 1){
	    cout << " - Objeto " << i << " -> Peso: " << p[i] << " - Beneficio: " << b[i] << "\n";
	    peso_total += p[i];
	    beneficio_total += b[i];
	  }
	  if(i == Sol.size() - 1){
	    cout << "\nPeso total: " << peso_total << "\nBeneficio total: " << beneficio_total << "\n";
	  }
	}

	return 0;
}
