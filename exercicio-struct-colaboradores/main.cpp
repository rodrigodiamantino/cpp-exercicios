/*Faça um programa com menu de três opções (1-ler linha, 2- mostrar e 3- sair), contendo um STRUCT para 
cadastrar o nome, a idade, o sexo, salário e salarioNovo de pelo menos duas pessoas. Crie um ponteiro
para manipular o STRUCT. O programa deverá conter as seguintes sub-rotinas abaixo (use switch case):
a) void NovaLinhaStruct() 
b) void listarLinhasStruct()
c) lerIdade()
d) lerSexo()
e) lerNome()
f) lerSalario()
g) getAumento(double * salario) // aumento de 10% sobre o salário digitado*/

#include <iostream>
#include <string>
#include <iomanip>
#include <locale>
#include <windows.h>
#define n 2
using namespace std;

struct dadosColaboradores {
    string nome[n], sexo[n];
    int idade[n];
    double salario[n], salarioNovo[n];
};

dadosColaboradores colaborador;
dadosColaboradores *ptColab = &colaborador;

int linha = -1;

int lerIdade() {
    int idade;

    cout << "Idade: ";
    cin >> idade;
    return idade;
}

string lerSexo() {
    string sexo;
    
    cout << "Sexo: ";
    getline(cin >> ws, sexo);
    return sexo;
}

string lerNome() {
    string nome;

    cout <<"Nome: ";
    getline(cin >> ws, nome);
    return nome;
}

double lerSalario() {
    double salario;

    cout << "Salário: ";
    cin >> salario;
    return salario;
} 

double getAumento(double *salario) {
    return (*salario * 0.1) + *salario;
}

void novaLinhaStruct() {
    linha++;

    if(linha >= n) {
        cout << "Limite excedido." << endl;
        linha--;
        return;
    }

    cout << "\nInsira as informações do colaborador." << endl;
    ptColab->nome[linha] = lerNome();
    ptColab->sexo[linha] = lerSexo();
    ptColab->idade[linha] = lerIdade();
    ptColab->salario[linha] = lerSalario();
    ptColab->salarioNovo[linha] = getAumento(&ptColab->salario[linha]);
}

void listarLinhasStruct() {
    if(linha == -1) {
        cout << "Nenhum colaborador cadastrado." << endl;
        Sleep(2000);
        return;
    }
    for(int i = 0; i <= linha; i++) {
        cout << "Colaborador " << i + 1 << "\nNome: " << ptColab->nome[i] << "\nSexo: " << ptColab->sexo[i] << "\nIdade: " << ptColab->idade[i] << " anos\n" << "Salário antigo: R$" << fixed << setprecision(2) << ptColab->salario[i] << "\nSalário novo: R$" << ptColab->salarioNovo[i] << endl << endl;
    }
}



int main() {
    setlocale(LC_ALL, "Portuguese");

    while(true) {
        system("cls");
        int opcao;
        cout << " ______________________" << endl;
        cout << "|                      |" << endl;
        cout << "|     *** MENU ***     |" << endl;
        cout << "|     1 - Ler linha    |" << endl;
        cout << "|   2 - Mostrar dados  |" << endl;
        cout << "| 3 - Sair do programa |" << endl;
        cout << "|______________________|" << endl;
        cout << "    Digite a opção: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                novaLinhaStruct();
                Sleep(3000);
                break;
            case 2:
                cout << endl;
                listarLinhasStruct();
                Sleep(5000);
                break;
            case 3:
                cout << "    Programa encerrado" << endl;
                return 0;
        }
    }
}