#include <iostream>
#include <numeric>
#include <stdlib.h>
using namespace std;

bool validarSubconjunto(int somarValores[], int particoes){
    int var = true;
    for (int i = 0; i < particoes; i++){
        if (somarValores[i] != 0) {
            var = false;
        }
    }
    return var;
}
 
bool conjuntoSubconjunto(int subconjunto[], int n, int somarValores[], int vetor[], int particoes){
    if (validarSubconjunto(somarValores, particoes)) {
        return true;
    }
 
    if (n < 0) {
        return false;
    }
 
    bool somatorio = false;
 
    for (int i = 0; i < particoes; i++){
        if (!somatorio && (somarValores[i] - subconjunto[n]) >= 0){
           
            vetor[n] = i + 1;
            somarValores[i] = somarValores[i] - subconjunto[n];
            somatorio = conjuntoSubconjunto(subconjunto, n - 1, somarValores, vetor, particoes);
            somarValores[i] = somarValores[i] + subconjunto[n];
        }
    }
    return somatorio;
}
 
void conjuntoParticao(int subconjunto[], int n, int particoes){
    
    if (n < particoes){
        cout << "\nN�o � possivel dividir com esse n�mero de partic�es\n";
        return;
	}
 
    int soma = accumulate(subconjunto, subconjunto + n, 0);
 
	int vetor[n], somarValores[particoes];
 
    for (int i = 0; i < particoes; i++) {
        somarValores[i] = soma/particoes;
    }
 
    bool somatorio = !(soma % particoes) && conjuntoSubconjunto(subconjunto, n - 1, somarValores, vetor, particoes);
 
    if (!somatorio){
        cout << "\nN�o � possivel dividir com esse n�mero de partic�es\n";
        return;
    }
 
    for (int i = 0; i < particoes; i++){
        cout << "\n\tParti��o N�mero " << i << " --> ";
        for (int j = 0; j < n; j++){
            if (vetor[j] == i + 1) {
                cout << subconjunto[j] << " ";
            }
        }
        cout << endl;
    }
}
 
int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
		int i;
		int x;

		cout <<" Qual o tamanho do vetor que voc� vai preencher ? ";
			cin >> x;
			
		int subconjunto[x];
	
		for(i=0;i<x; i++){
			cout<< "\n\tEntre com o " << i+1 << "� valor " "--> ";
				cin >> subconjunto[i];
		
		}
		
		int particoes = 0;
    	int n = sizeof(subconjunto) / sizeof(subconjunto[0]);
    	
	    cout << "\n -------------------------------------------------------\n";
		cout << "\n Em quantas particoes voce quer dividir ? ";
			cin >> particoes;
 
    	conjuntoParticao(subconjunto, n, particoes);
 
    return 0;
}
