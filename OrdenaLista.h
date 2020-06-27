#include <cstdlib>
#include <iostream>
#include <list>
#include <string>

#include "Arvore.h"

using namespace std;

list<Arvore> OrdenaLista(list<Arvore> lista){
   int  maior_valor;
   string maior_caracter;
   list<Arvore> lista_nova;
   list<Arvore> lista_ordenada;
   list<Arvore>::iterator it;

   while (lista.size() != 0){
      maior_valor = 0;
      for (it = lista.begin(); it != lista.end(); it++){
         if (it->getQuantidade() > maior_valor){
            maior_valor    = it->getQuantidade();
            maior_caracter = it->getCaracter();
            lista_nova.push_back(*it);
         }
      }

      //Exclui nó com valor máximo e Incluir nó na lista ordenada.
      for (it = lista.begin(); it != lista.end(); it++){
         if (it->getQuantidade() == maior_valor && it->getCaracter() == maior_caracter){
               lista.erase(it);
               break;
         }
      }

      lista_ordenada.push_front(lista_nova.back());
      lista_nova.clear();
   }

   return lista_ordenada;

};
