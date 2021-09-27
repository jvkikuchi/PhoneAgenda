#include <iostream>
#include "agenda.cpp"
#define N 2

using namespace std;

void menu();
string informar(string variavel);

int main(){
    Agenda agenda;
    Contato contato;
    Pessoa pessoa;

    int input = -1;
    int controlador = 0;

    while (input) {
        menu();
        cin >> input;
        switch (input) {
            case 1: { 
                pessoa.setNome(informar("nome"));
                contato.setPessoa(pessoa);
                contato.setWhatsapp(informar("whatsapp"));
                agenda.armazenarContato(contato,controlador++);
            }; break;

            case 2: 

            agenda.listarContato();
    
            break;

            case 3: break; // editarContato()

            case 4:
                contato.setWhatsapp(informar("whatsapp"));
                agenda.removerContato(contato);
                agenda.listarContato();
            break;
        }
    }
}

void menu() {
    string output = "";
    output = "\nMENU:\n";
    output += "(1) Adicionar contato\n";
    output += "(2) Exibir contatos\n";
    output += "(3) Editar contatos\n";    
    output += "(4) Remover contato\n";
    output += "(0) Sair\n";
    output += "ESCOLHA: ";
    cout << output;
}

string informar(string variavel) {
    string elem;
    cout << "Digite seu " + variavel + ": ";
    cin >> elem;
    return elem;
}
