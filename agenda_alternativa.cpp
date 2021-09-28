#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "contato.cpp"
#include "utils.h"

using namespace std;

class Agenda {

    public:
        Agenda() {
            carregarContatos();
        }
        
        void armazenarContato(Contato contato) {
            agenda.push_back(contato);
        }

        void buscarContato(string regex) {
            if (regex.length() < 3) {
                cout << "O termo de busca deve conter pelo menos 3 caracteres." << endl;
                return;
            }
            bool found = false;
            for(auto contato : agenda) {
                if (toLowerCase(contato.getPessoa().getNome()).find(toLowerCase(regex)) != string::npos) {
                    print(contato);
                    found = true;
                }
            }
            if (!found) {
                cout << "Nenhum registro encontrado." << endl;
            }
        }

        void editarContato(string regex) {
            bool found = false;
            for(auto &contato : agenda) {
                if (toLowerCase(contato.getWhatsapp()).find(toLowerCase(regex)) != string::npos) {
                    print(contato);
                    found = true;
                    pessoa.setNome(informar("\nNovo nome"));
                    pessoa.setIdade(stoi(informar("Nova idade")));
                    pessoa.setEndereco(informar("Novo endereco"));
                    contato.setPessoa(pessoa);
                    contato.setEmail(informar("Novo email"));
                    contato.setWhatsapp(informar("Novo whatsapp"));
                    contato.setDiscord(informar("Novo discord"));
                }
            }
            if (!found) {
                cout << "Nenhum registro encontrado." << endl;
            }
        }

        void gravarArquivo() {
            saveFile();
        }

        string informar(string variavel) {
            string elem;
            cout << variavel + ": ";
            cin >> elem;
            return elem;
        }

        void listarContatos() {
            for ( auto contato : agenda ) {
                print(contato);
            }
        }

        void print(Contato contato) {
            Pessoa pessoa = contato.getPessoa();
            string buffer = "\nNome: " + pessoa.getNome();
            buffer += "\nIdade: " + to_string(pessoa.getIdade());
            buffer += "\nEndereco: " + pessoa.getEndereco();
            buffer += "\nEmail: " + contato.getEmail();
            buffer += "\nWhatsapp: " + contato.getWhatsapp();
            buffer += "\nDiscord: " + contato.getDiscord();
            cout << buffer << endl;
        }

        void removerContato(string whatsapp) {
            bool found = false;
            for (vector<Contato>::iterator it = agenda.begin(); it != agenda.end(); ++it) {
                if (!found && it->getWhatsapp() == whatsapp) {
                    agenda.erase(it);
                    found = true;
                }
            }
            if (!found) {
                cout << "Nenhum registro encontrado." << endl;
            }
        }

    private:
        vector<Contato> agenda;
        Contato contato;
        Pessoa pessoa;
        void carregarContatos() {
            ifstream arquivo("data.xml");
            string line;
            bool openRegister = false;
            while(getline(arquivo,line)) {
                trim(line);
                if (line.find("<registro>") != string::npos) {
                    openRegister = true;
                }
                else if (line.find("<nome>") != string::npos && openRegister) {
                    line = replaceAll(line,"<nome>","");
                    line = replaceAll(line,"</nome>","");
                    pessoa.setNome(line);
                }
                else if (line.find("<idade>") != string::npos && openRegister) {
                    line = replaceAll(line,"<idade>","");
                    line = replaceAll(line,"</idade>","");
                    pessoa.setIdade(stoi(line));
                }
                else if (line.find("<endereco>") != string::npos && openRegister) {
                    line = replaceAll(line,"<endereco>","");
                    line = replaceAll(line,"</endereco>","");
                    pessoa.setEndereco(line);
                }
                else if (line.find("<email>") != string::npos && openRegister) {
                    line = replaceAll(line,"<email>","");
                    line = replaceAll(line,"</email>","");
                    contato.setEmail(line);
                }
                else if (line.find("<whatsapp>") != string::npos && openRegister) {
                    line = replaceAll(line,"<whatsapp>","");
                    line = replaceAll(line,"</whatsapp>","");
                    contato.setWhatsapp(line);
                }
                else if (line.find("<discord>") != string::npos && openRegister) {
                    line = replaceAll(line,"<discord>","");
                    line = replaceAll(line,"</discord>","");
                    contato.setDiscord(line);
                }
                else if (line.find("</registro>") != string::npos) {
                    contato.setPessoa(pessoa);
                    agenda.push_back(contato);
                    openRegister = false;
                }
            }
            arquivo.close();
        }

        void saveFile() {
            ofstream arquivo("data.xml");
            arquivo << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
            arquivo << "<agenda>\n";
            for (auto contato : agenda) {
                arquivo << tabs(1) + "<registro>\n";
                arquivo << tabs(2) + "<nome>" + contato.getPessoa().getNome() + "</nome>\n";
                arquivo << tabs(2) + "<idade>" + to_string(contato.getPessoa().getIdade()) + "</idade>\n";
                arquivo << tabs(2) + "<endereco>" + contato.getPessoa().getEndereco() + "</endereco>\n";
                arquivo << tabs(2) + "<email>" + contato.getEmail() + "</email>\n";
                arquivo << tabs(2) + "<whatsapp>" + contato.getWhatsapp() + "</whatsapp>\n";
                arquivo << tabs(2) + "<discord>" + contato.getDiscord() + "</discord>\n";
                arquivo << tabs(1) + "</registro>\n";
            }
            arquivo << "</agenda>\n";
            arquivo.close();
        }

        string tabs(int n) {
            int tabSize = 4; 
            string tabs = "";
            for (int i = 0; i < n * tabSize; i++) {
                tabs += " ";
            }
            return tabs;
        }
    
};
