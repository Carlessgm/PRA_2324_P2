#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Cambio(vector<int> v, int M, int n){
	//n = Tamaño vector v (núm. monedas)
	int T[n][M + 1];
	int i, j;

	for(i = 0; i < n; i++){
		for(j = 0; j < M + 1; j++){
			T[i][j] = -1;
		}
	}

	T[0][0] = 0;
	T[1][0] = 0;
	T[2][0] = 0;

	for(j = 1; j < M + 1; j++){
		if(j >= v[0] && T[0][j - v[0]] != -1){
			T[0][j] = 1 + T[0][j - v[0]];
		}
	}
	
	for(i = 1; i < n; i++){
		for(j = 1; j < M + 1; j++){
			if(j < v[i] || T[i][j - v[i]] == -1){
				T[i][j] = T[i - 1][j];
			}
			else if(T[i - 1][j] != -1){
				T[i][j] = min(T[i - 1][j], 1 + T[i][j - v[i]]);
			}
			else{
				T[i][j] = 1 + T[i][j - v[i]];
			}
		}
	}

	for(i = 0; i < n; i++){
                for(j = 0; j < M + 1; j++){
                        cout << T[i][j] << " ";
                }
		cout << "\n";
        }
	cout << "\n";

	vector<int> Sol(n);
	i = n - 1;
	j = M;

	while(i != 0 && j != 0){
		if(i == 0 || T[i][j] != T[i - 1][j]){
			Sol[i] = Sol[i] + 1;
			j = j - v[i];
		}
		else{
			i = i - 1;
		}
	}


	return Sol;
}

int main(){
	vector<int> v{1, 4, 6};
	int P = 8; 				//Cantidad a buscar
	int x;
	vector <int> Sol = Cambio(v, P, v.size());

	for(int i = 0; i < Sol.size(); i++){
		cout << "Monedas de " << v[i] << ": " << Sol[i] << " \n";
	}

	cout << "\n";
	return 0;
}
