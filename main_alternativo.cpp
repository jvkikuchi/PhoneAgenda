#include <iostream>
#include "agenda_alternativa.cpp"

using namespace std;

Agenda agenda;
Contato contato;
Pessoa pessoa;

void menu();
void adicionarContato();
void editarContato();
string informar(string variavel);

int main() {
    int input = -1;
    while (input) {
        menu();
        cin >> input;
        switch (input) {
            case 1: adicionarContato(); break;
            case 2: agenda.listarContatos(); break;
            case 3: agenda.buscarContato(informar("Buscar por")); break;
            case 4: agenda.editarContato(informar("Whatsapp")); break;
            case 5: agenda.removerContato(informar("Whatsapp")); break;
            case 6: agenda.gravarArquivo(); break;
        }
    }
}

void menu() {
    string output = "";
    output = "\nMENU:\n";
    output += "(1) Adicionar contato\n";
    output += "(2) Exibir contatos\n";
    output += "(3) Buscar contato\n";
    output += "(4) Editar contato\n";    
    output += "(5) Remover contato\n";
    output += "(6) Salvar contatos\n";
    output += "(0) Sair\n";
    output += "ESCOLHA: ";
    cout << output;
}

void adicionarContato() {
    pessoa.setNome(informar("Nome"));
    pessoa.setIdade(stoi(informar("Idade")));
    pessoa.setEndereco(informar("Endereco"));
    contato.setPessoa(pessoa);
    contato.setEmail(informar("Email"));
    contato.setWhatsapp(informar("Whatsapp"));
    contato.setDiscord(informar("Discord"));
    agenda.armazenarContato(contato);
}

string informar(string variavel) {
    string elem;
    cout << variavel + ": ";
    cin >> elem;
    return elem;
}
