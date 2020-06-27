#include <string>
#include <cstdlib>

using namespace std;

class Arvore{   
   private:
      int quantidade;
      string caracter;
      int bits;
      Arvore *esquerda;
      Arvore *direita;     
 
   public:
      Arvore();
      Arvore(int quantidade, string caracter, int bits, Arvore *esquerda, Arvore *direita);
      ~Arvore();    
      int getQuantidade();
      string getCaracter();
      int getBits();
      Arvore *getEsquerda();
      Arvore *getDireita();
      void setQuantidade(int quantidade);
      void setCaracter(string caracter);
      void setBits(int bits);
      void setEsquerda(Arvore *esquerda);
      void setDireita(Arvore *direita);
};

Arvore::Arvore(){
};

Arvore::Arvore(int quantidade, string caracter, int bits, Arvore *esquerda, Arvore *direita){
   this->quantidade = quantidade;
   this->caracter = caracter;
   this->bits = 0;
   this->esquerda = esquerda;
   this->direita = direita;
};

Arvore::~Arvore(){
};

int Arvore::getQuantidade(){
   return this->quantidade;
};

string Arvore::getCaracter(){
   return this->caracter;
};

int Arvore::getBits(){
   return this->bits;
};

Arvore *Arvore::getEsquerda(){
   return this->esquerda;
};

Arvore *Arvore::getDireita(){
   return this->direita;
};

void Arvore::setQuantidade(int quantidade){
   this->quantidade = quantidade;     
};

void Arvore::setCaracter(string caracter){
   this->caracter = caracter;
};

void Arvore::setBits(int bits){
   this->bits = bits;
};

void Arvore::setEsquerda(Arvore *esquerda){
   this->esquerda = esquerda;
};

void Arvore::setDireita(Arvore *direita){
   this->direita = direita;
};
