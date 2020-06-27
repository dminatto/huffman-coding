#include <cstdlib>
#include <iostream>
#include <list>
#include <string>

using namespace std;

list<Arvore> montaArvoreBinariaCompleta(list<Arvore> lista){
   int intContador, quantidadeNovaPosicao;
   Arvore *pos1 = new Arvore();
   Arvore *pos2 = new Arvore();

   list<Arvore>::iterator it;
   intContador = 1;
   //Pegando as duas primeiras posi��es
   for (it = lista.begin(); it != lista.end(); it++){
       switch(intContador){
       case 1:
          pos1->setQuantidade(it->getQuantidade());
          pos1->setCaracter(it->getCaracter());
          pos1->setEsquerda(it->getEsquerda());
          pos1->setDireita(it->getDireita());
          pos1->setBits(0);
          break;
       case 2:
          pos2->setQuantidade(it->getQuantidade());
          pos2->setCaracter(it->getCaracter());
          pos2->setEsquerda(it->getEsquerda());
          pos2->setDireita(it->getDireita());
          pos2->setBits(1);
          break;
       }
       if (intContador > 2)
          break;
       intContador++;
   }

   //Verifica se a lista tem apenas um registro, sen�o tiver continuar� o processo recursivamente.
   if (intContador != 2){
      //Cria nova posi��o na lista.
      quantidadeNovaPosicao = (pos1->getQuantidade() + pos2->getQuantidade());
      Arvore *novaPosicao    = new Arvore(quantidadeNovaPosicao, "%", 0, pos1, pos2);
      lista.push_back(*novaPosicao);

      //Exclui as referencias das duas posi��es removendo-as da lista.
      for (it = lista.begin(); it != lista.end(); it++){
         if (it->getQuantidade() == pos1->getQuantidade() && it->getCaracter() == pos1->getCaracter()){
            lista.erase(it);
            break;
         }
      }
      for (it = lista.begin(); it != lista.end(); it++){
         if (it->getQuantidade() == pos2->getQuantidade() && it->getCaracter() == pos2->getCaracter()){
            lista.erase(it);
            break;
         }
      }
      //Ordena lista rec�m alterada.
      lista = OrdenaLista(lista);
      //Chama novamente a fun��o (recursividade)
      lista = montaArvoreBinariaCompleta(lista);
   }

   return lista;

};
