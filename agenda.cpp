#include <iostream>
#include "contato.cpp"

#define MAX 10

using namespace std;

class Agenda{

private:
    Contato contato[MAX];
    Pessoa pessoa[MAX];

public:

    void armazenarContato(Contato contato, int i){
        this->contato[i] = contato;
    }

    void listarContato(){
        for(int i = 0; i < MAX; i++){
            cout << i + 1 << ". " << contato[i].toString() << endl;
        }
    }

    void removerContato(Contato contato) {
        int wanted = -1;
        bool found = false;
        for(int i = 0; i < MAX; i++){
            if(this->contato[i].getWhatsapp() == contato.getWhatsapp()){
                wanted = i;
                found = true;
            }
        }
        if (found) {
            this->contato[wanted].reset();
            for(int i = wanted; i < MAX; i++){
                this->contato[i] = this->contato[i+1];
                // this->contato[i].copy(this->contato[i+1]);
            }
            this->contato[MAX - 1].reset();
        }
    }

    // funcao que informa algum erro
    void error(int code) {
        string msg;
        switch (code) {
            case 0: break;
            case 1: msg = "Erro: Usuario nao encontrado"; break;
            default: msg = "Erro Desconhecido";
        }
        cout << msg << endl;
    }
};