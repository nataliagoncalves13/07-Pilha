#include <iostream>
#include <cstdio>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* topo = NULL;

// headers
void menu();
void inicializar();
void k_pop();
void push();
void exibir();
//--------------------------


int main(){
	menu();
}

void menu(){
	int op = 0;
	while (op != 4) {
		system("clear"); // somente no windows
		cout << "Menu Pilha";
		cout << endl << endl;
		cout << "1 - Inicializar Pilha \n";
		cout << "2 - Inserir elemento (Push) \n";
		cout << "3 - Remover elementos (Pop) \n";
		cout << "4 - Sair \n";
		cout << "5 - Exibir elementos \n"; 


		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:push();
			break;
		case 3: k_pop();
			break;
		case 5: exibir();
		    break;
		case 4:
			return;
		default:
			break;
		}

		getchar(); // somente no windows
	}
}

void inicializar(){

	// se a lista j� possuir elementos
	// libera a memoria ocupada
	NO* aux = topo;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	topo = NULL;
	cout << "Pilha inicializada \n";
	getchar();

}


void push(){
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;
	
	if (topo == NULL){
	    topo = novo;
	}
	else
	{
	    novo->prox = topo;
	    topo = novo;
	}
	getchar();

}

void k_pop(){
    NO* jimin = topo;
    topo = topo->prox;
    cout << "Você deletou o kpoper número: " << jimin->valor;
    free(jimin);
	getchar();

}

void exibir(){
    NO* aux =topo;
    while(aux!=NULL){
        cout<<aux->valor<<endl;
        aux=aux->prox;
    }
    getchar();
}


