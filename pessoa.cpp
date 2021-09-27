#include <iostream>

using namespace std;

class Pessoa{

private:    
    string nome;
    int idade;
    string endereco;

public:

    Pessoa(){
        reset();
    }

    string getNome(){
        return nome;
    }

    void setNome(string nome){
        this->nome = nome;
    }

    int getIdade(){
        return idade;
    }

    void setIdade(int idade){
        this->idade = idade;
    }

    string getEndereco(){
        return endereco;
    }

    void setEndereco(string endereco){
        this->endereco = endereco;
    }

    void reset(){
        nome = "vazio";
        endereco = "vazio";
        idade = 0;
    }

    bool equals(Pessoa pessoa){
    
        if (this->nome != pessoa.getNome()) {
            return false;
        }
        if (this->endereco != pessoa.getEndereco()) {
            return false;
        }
        if (this->idade != pessoa.getIdade()) {
            return false;
        }

        return true;
        
    }
};