#include <iostream>
#include <string>
#include "pessoa.cpp"

using namespace std;

class Contato{

private:
    Pessoa pessoa;    
    string email;
    string whatsapp;
    string discord;

public:

    Contato(){
        reset();
    }

    Pessoa getPessoa(){
        return pessoa;
    }

    void setPessoa(Pessoa pessoa){
        this->pessoa = pessoa;
    }

    string getDiscord(){
        return discord;
    }

    void setDiscord(string discord){
        this->discord = discord;
    }

    string getEmail(){
        return email;
    }

    void setEmail(string email){
        this->email = email;
    }

    string getWhatsapp(){
        return whatsapp;
    }

    void setWhatsapp(string whatsapp){
        this->whatsapp = whatsapp;
    }

    void reset(){
        pessoa.reset();
        discord = "vazio";
        email = "vazio";
        whatsapp = "vazio";
    }
    
    bool equals(Contato contato){
        if (!getPessoa().equals(contato.getPessoa())) {
            return false;
        }
        if (this->discord != contato.getDiscord()) {
            return false;
        }
        if (this->email != contato.getEmail()) {
            return false;
        }
        if (this->whatsapp != contato.getWhatsapp()) {
            return false;
        }
        return true;
    }
    

    string toString(){
        return pessoa.getNome() + " " + whatsapp;
    }
};