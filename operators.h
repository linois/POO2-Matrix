/* ---------------------------
Laboratoire :  Labo 01 : Matrix Reloaded
Fichier     :  operators.h
Auteur(s)   :  Edouard de Chambrier, Valvona Guillaume
Date        :  27.02.2020

Remarque(s) : Ce fichier contient plusieurs classes, vu que chacune de celle-ci est
              d'une taille relativement petite.
              Au vue de la petite taille des méthodes, il n'y a pas de fichiers
              .cpp non plus

Compilateur :  MinGW-g++ 6.3.0
--------------------------- */

#ifndef OPERATORS_H
#define OPERATORS_H

class Operator {
public:
   virtual int apply(int lhs, int rhs)const = 0;
};

class Add:public Operator{
public:
   int apply(int lhs, int rhs)const{
      return lhs + rhs;
   }
};

class Sub:public Operator{
public:
   int apply(int lhs, int rhs)const{
      return lhs - rhs;
   }
};

class Mul:public Operator{
public:
   int apply(int lhs, int rhs)const{
      return lhs * rhs;
   }
};

#endif /* OPERATORS_H */

