#include <iostream>
using namespace std;

class No {

    private:
        Arvore no;
        No *prox;

    public:
        Arvore getNo(); //Retorna o nó
        void setNo(Arvore no); //Seta um nó para a classe Lista
        No *getProx();
        void setProx(No *no);
        No();
        No(Arvore no);
};

Arvore No::getNo(){
    return this->no;
}

void No::setNo(Arvore no){
    this->no = no;
}

No::No(){
}

No::No(Arvore no){
    setNo(no);
    this->prox = NULL;
}

No* No::getProx(){
    return prox;
}

void No::setProx(No *no){
    this->prox = no;
}
