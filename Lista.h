#include <iostream>
#include "No.h"
using namespace std;

class Lista {

    private:
        No *first;

    public:
        Lista(Arvore no); //Construtor
        Lista(); //Construtor sem parâmetros
        ~Lista(); //Destrutor
        void inserirInicio(Arvore no); //Inserir um nó no início da lista
        void inserirFim(Arvore no); //Inserir um nó no fim da lista
        void inserirOrdem(Arvore no); //Insere em ordem na lista pela quantidade
        void removerNo(int quantidade, string caracter); //Remove um nó da lista
        No* consultarNo(int quantidade, string caracter); //Retorna o nó consultado
        No* removeRetorna(int quantidade, string caracter); //Remove o nó da lista retornando
                                                              //para uma variável externa
        void printLista(); //Imprime todos os nós da lista
        void reordenar(); //Reoordena a lista em modo ascendente com base na quantidade
        No* buscaUltimo(); //Retorna o ultimo nó da lista

        //Os métodos get e set do nó first só serão usado quando passar uma informação de uma lista para outra
        No* getFirst(); //Retorna o endereço do primeiro nó da lista
        void setFirstNULL(); //Seta o primeiro como nulo
};

Lista::Lista(){
    first = NULL;
}

Lista::Lista(Arvore no){
    first->setNo(no);
}

Lista::~Lista(){

    No *aux = first;

    if(aux != NULL){
        No *guarda = aux;
        aux = aux->getProx();
        delete guarda;
    }

}

No* Lista::getFirst(){
    return this->first;
}

void Lista::inserirInicio(Arvore no){

    No *novo = new No(no);
    novo->setProx(first);
    first = novo;

}

No* Lista::buscaUltimo(){

    No *aux = first;

    if(aux == NULL) return NULL;

    while(aux->getProx() != NULL) aux = aux->getProx();

    return aux;

}

void Lista::inserirFim(Arvore no){

    if(first == NULL){
        inserirInicio(no);
    } else {
        No *novo = new No(no);
        No *aux = buscaUltimo();
        aux->setProx(novo);
    }

}

void Lista::inserirOrdem(Arvore no){

    if(first == NULL){
        inserirInicio(no);
    } else {
        No *anterior = first, *aux = first;

        if(aux->getNo().getQuantidade() > no.getQuantidade()){ //Se vier antes do first
            inserirInicio(no);
            return;
        }

        No *novo = new No(no);

        while(aux->getNo().getQuantidade() < novo->getNo().getQuantidade()){
            if(aux->getProx() != NULL){
                anterior = aux;
                aux = aux->getProx();
            }
            else { //caso não tenha mais posições a direita
                anterior = aux;
                aux = aux->getProx();
                break;
            }
        }

        novo->setProx(aux);
        anterior->setProx(novo);
    }

}

void Lista::removerNo(int quantidade, string caracter){

    No *aux = first;
    No *anterior = first;

    //Caso a exclusão seja o primeiro nó
    if(aux != NULL){
        if(aux->getNo().getQuantidade() == quantidade &&
           aux->getNo().getCaracter() == caracter){
                anterior = aux->getProx();
                delete aux;
                first = anterior;
           }
    }

    while(aux != NULL){

        if(aux->getNo().getQuantidade() == quantidade &&
           aux->getNo().getCaracter() == caracter)
        {
            anterior->setProx(aux->getProx());
            delete aux;
        }

        anterior = aux;
        aux = aux->getProx();

    }

}

No* Lista::consultarNo(int quantidade, string caracter){

    No *aux = first;

    while(aux != NULL){

        if(aux->getNo().getQuantidade() == quantidade &&
           aux->getNo().getCaracter() == caracter)
        {
            return aux;
        }

        aux = aux->getProx();
    }

    cout << "Nao existe no com essa informacao na lista" << endl;
    return NULL;

}

No* Lista::removeRetorna(int quantidade, string caracter){

    No *aux;
    No *copia = new No();

    aux = consultarNo(quantidade, caracter);

    if(aux != NULL){
        copia->setNo(aux->getNo());
        removerNo(quantidade, caracter);
    }

    return copia;
}

void Lista::printLista(){

    No *aux = first;

    int cont = 1;

    while(aux != NULL){

        cout << "No " << cont << ": " << aux->getNo().getQuantidade() << " - " <<
                                         aux->getNo().getCaracter() << endl;
        aux = aux->getProx();
        cont++;
    }

}

void Lista::setFirstNULL(){
    this->first = NULL;
}

void Lista::reordenar(){

    No *aux = first;
    Lista *seg = new Lista();
    No *no = new No();

    while(aux != NULL){

        Arvore dados = aux->getNo();
        no = this->removeRetorna(dados.getQuantidade(), dados.getCaracter());
        seg->inserirOrdem(no->getNo());
        aux = first;

    }

    first = seg->getFirst();
    seg->setFirstNULL(); //seta como nulo o ponteiro que conhece o primeiro endereço da
                         //segunda lista, para que ao executar o delete, o destrutor não
                         //elimine toda a lista
    delete seg;

}
