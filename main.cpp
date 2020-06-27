#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>

#include "OrdenaLista.h"
#include "montaArvoreBinariaCompleta.h"
#include "Lista.h"



using namespace std;

void emOrdem(Arvore *pNo) {

    if(pNo != NULL) {
        cout << pNo->getCaracter() << " - " << pNo->getQuantidade() << " - " << pNo->getBits() << endl;
        emOrdem(pNo->getEsquerda());
        emOrdem(pNo->getDireita());
    }
 }

void geraCabecalho(Arvore *pNo, string &strCabe){

    if(pNo != NULL) {
        if (pNo->getEsquerda() == NULL && pNo->getDireita() == NULL){
            strCabe += "1" + pNo->getCaracter();
        }else{
            strCabe += "0";
        }
        geraCabecalho(pNo->getEsquerda(), strCabe);
        geraCabecalho(pNo->getDireita(), strCabe);
    }
 }

void geraSequencia(Arvore *no, string str){

    string car = "";
    stringstream ss;

    if(no != NULL){

        ss << no->getBits();
        car = ss.str();

        if(no->getEsquerda() == NULL && no->getDireita() == NULL){
            cout << no->getCaracter() << ": " << str + car << endl;
        }

        geraSequencia(no->getEsquerda(), str + car);
        geraSequencia(no->getDireita(), str + car);

    }
}

int main(int argc, char *argv[]){
    fstream arqB;
    char letra[1];
    char arquivoOrigem[10];
    string strLetra;
    string strCabecalho;
    size_t caracter;
    bool jaExisteLista;

    list<Arvore> lista;
    list<Arvore> lista_ordenada;
    list<Arvore>::iterator it;
    Arvore *raiz = new Arvore();

    //Monta a lista encadeada com os caracteres e quantidade.
    cout << "Digite o arquivo: ";
    cin >> arquivoOrigem;
    arqB.open(arquivoOrigem,ios::in);
    while(!arqB.eof()){
        jaExisteLista = false;
        arqB.read(letra,1);
        letra[1]=0;
        if(!arqB.eof())
        {
            strLetra = letra[0];
            for (it = lista.begin(); it != lista.end(); it++){
                if (it->getCaracter() == strLetra){
                    it->setQuantidade(it->getQuantidade() + 1);
                    jaExisteLista  = true;
                }
            }
            if (jaExisteLista == false){
                Arvore *arvore_nova = new Arvore(1, strLetra, 0, NULL, NULL);
                lista.push_back(*arvore_nova);
            }
        }
    }
    arqB.close();
    lista_ordenada = OrdenaLista(lista);
    //Imprime lista ordenada.
    for (it = lista_ordenada.begin(); it != lista_ordenada.end(); it++)
        cout << it->getCaracter() << " - " << it->getQuantidade() << endl;
    //Monta arvore completa de Huffman
    lista_ordenada = montaArvoreBinariaCompleta(lista_ordenada);
    //Seta raiz da arvore completa de Huffman
    for (it = lista_ordenada.begin(); it != lista_ordenada.end(); it++){
        raiz->setCaracter(it->getCaracter());
        raiz->setQuantidade(it->getQuantidade());
        raiz->setEsquerda(it->getEsquerda());
        raiz->setDireita(it->getDireita());
        raiz->setBits(2);
    }
    //Remove lista da memória
    lista_ordenada.clear();
    emOrdem(raiz);
    geraSequencia(raiz->getEsquerda(), "");
    geraSequencia(raiz->getDireita(), "");
    strCabecalho = "";
    geraCabecalho(raiz,strCabecalho);
    cout << strCabecalho << endl;
}
