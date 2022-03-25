#include <iostream>
#include <locale.h>
#include <vector>

using namespace std;

int opcoes = 0;

void representacao(vector<vector<int> > & tab, int qtde){
	
	for(int i = 0; i < qtde; i++){
		for(int j = 0; j < qtde; j++){
			if(tab[i][j] == 1)
				cout << "\tR\t";
			else
				cout << "\t-\t";
		}
		cout << "\t\n";
	}
	cout << "\n";
}

bool alocar(vector<vector<int> > & matriz, int qtde, int linha, int coluna){
	int i, j;

	for(i = 0; i < qtde; i++){
		if(matriz[linha][i] == 1)
			return false;
			
		else if(matriz[i][coluna] == 1)
			return false;
	}

	for(i = linha, j = coluna; i >= 0 && j >= 0;  i--, j--){
		
		if(matriz[i][j] == 1)
			return false;
	}
	for(i = linha, j = coluna; i < qtde && j < qtde; i++, j++){
		
		if(matriz[i][j] == 1)
			return false;
	}

	for(i = linha, j = coluna; i >= 0 && j < qtde; i--, j++){
		
		if(matriz[i][j] == 1)
			return false;
	}
	for(i = linha, j = coluna; i < qtde && j >= 0; i++, j--){
		
		if(matriz[i][j] == 1)
			return false;
	}
	return true;
}

void resolver(vector<vector<int> > & matriz, int qtde, int coluna){
	
	if(coluna == qtde){
		cout << "\n\t\t\tOpção " << opcoes + 1 << ":\n\n";
		representacao(matriz, qtde);
		opcoes++;
		return;
	}

	for(int i = 0; i < qtde; i++){
		
		if(alocar(matriz, qtde, i, coluna)){
			matriz[i][coluna] = 1;
			resolver(matriz, qtde, coluna + 1);

			matriz[i][coluna] = 0;
		}
	}
}

int main(int argc, char *argv[]){
	
	setlocale(LC_ALL, "Portuguese");
	
		int qtde = 0;
		
		cout << "\n -------------------------------------------------------\n";
		cout << "\n Quantas rainhas terá no seu tabuleiro?\t";
			cin >> qtde;
	
		vector<vector<int> > matriz;
	
		for(int i = 0; i < qtde; i++){	
			vector<int> linha(qtde);
			matriz.push_back(linha);
		}
	
		resolver(matriz, qtde, 0);

		cout << "\nExistem " << opcoes << " opções possiveis\n";

	return 0;
}
