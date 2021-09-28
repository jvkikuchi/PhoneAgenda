#include <iostream>
#include "agenda_alternativa.cpp"

using namespace std;

void menu();
string informar(string variavel);

int main() {
    Agenda agenda;
    Contato contato;
    Pessoa pessoa;
    int input = -1;
    while (input) {
        menu();
        cin >> input;
        switch (input) {
            case 1: { 
                pessoa.setNome(informar("Nome"));
                pessoa.setIdade(stoi(informar("Idade")));
                pessoa.setEndereco(informar("Endereco"));
                contato.setPessoa(pessoa);
                contato.setEmail(informar("Email"));
                contato.setWhatsapp(informar("Whatsapp"));
                contato.setDiscord(informar("Discord"));
                agenda.armazenarContato(contato);
            }; break;
            case 2: agenda.listarContatos(); break;
            case 3: {
                string regex = informar("Buscar por");
                if (regex.length() < 3) {
                    cout << "O termo de busca deve conter pelo menos 3 caracteres." << endl;
                }
                else {
                    agenda.buscarContato(regex);
                }
            }; break; // editarContato()
            case 4: break;
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
    output += "(4) Editar contatos\n";    
    output += "(5) Remover contato\n";
    output += "(6) Salvar contatos\n";
    output += "(0) Sair\n";
    output += "ESCOLHA: ";
    cout << output;
}

string informar(string variavel) {
    string elem;
    cout << variavel + ": ";
    cin >> elem;
    return elem;
}
