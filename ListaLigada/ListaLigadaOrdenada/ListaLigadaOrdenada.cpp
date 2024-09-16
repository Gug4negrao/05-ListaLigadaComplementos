#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	int valorDigitado;
	bool inserido = false;
	cout << "Digite o elemento: ";
	cin >> valorDigitado;

	if (primeiro == NULL)
	{
		novo->valor = valorDigitado;
		novo->prox = NULL;
		primeiro = novo;
		ultimo = novo;
		bool inserido = true;
		return;
	}
	else
	{
		NO* aux = primeiro;
		bool igual = false;
		while (aux->prox != NULL) {
			if (aux->valor == valorDigitado) {
				igual = true;
			}
			aux = aux->prox;
		} 

		if (igual == true) {
			cout << "O elemento digitado ja existe na lista atual." << endl;
			return;
		}
		else {
			aux = primeiro;
			novo->valor = valorDigitado;
			novo->prox = NULL;
			NO* auxAnterior = NULL;

			do {
				if (primeiro->valor == ultimo->valor) {
					if (aux->valor > novo->valor) {
						novo->prox = aux;
						primeiro = novo;
						inserido = true;
						return;
					}
					else {
						aux->prox = novo;
						inserido = true;
						return;
					}
				}
				else {
					if (aux->valor > novo->valor) {
						if (auxAnterior != NULL) {
							auxAnterior->prox = novo;
							novo->prox = aux;
							inserido = true;
							return;
						}
						else {
							novo->prox = aux;
							primeiro = novo;	
							inserido = true;
							return;
						}
					}
					else {	
						auxAnterior = aux;
						aux = aux->prox;
						return;
					}
				}
			} while (aux->prox != NULL);
			if (inserido = false) {
				aux->prox = novo;
			}
		}
	}
}

void excluirElemento()
{

}

void buscarElemento()
{

}


