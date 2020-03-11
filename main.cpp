/* ---------------------------
Laboratoire :  Labo 01 : Matrix Reloaded
Fichier     :  main.cpp
Auteur(s)   :  Edouard de Chambrier, Valvona GUillaume
Date        :  27.02.2020

But         : Vérifier le bon fonctionnement de la calsse Matrix

Compilateur :  MinGW-g++ 6.3.0
--------------------------- */

#include <cstdlib>
#include "Matrix.h"

using namespace std;

int main(int argc, char** argv) {
   
   cout << "Test : operations that modify the matrix :" << endl;
   const int MODT1 = 5;
   cout << "The modulus is " << MODT1 << endl << endl;
   Matrix m1t1(4,3,MODT1);
   Matrix m2t1(5,3,MODT1);

   cout << "one" << endl;
   cout << m1t1 << endl << endl;
   cout << "two" << endl;
   cout << m2t1 << endl << endl;
   
   cout << "one + two" << endl;
   cout << m1t1.addByModifyingMatrix(m2t1) << endl;
   
   cout << "one - two" << endl;
   cout << m1t1.subByModifyingMatrix(m2t1) << endl;
   
   cout << "one x two" << endl;
   cout << m1t1.mulByModifyingMatrix(m2t1) << endl << endl;


   cout << "Test : operations that return a Matrix as value :" << endl;
   const int MODT2 = 6;
   cout << "The modulus is " << MODT2 << endl << endl;
   Matrix m1t2(4,3,MODT2);
   Matrix m2t2(5,3,MODT2);
   
   cout << "one" << endl;
   cout << m1t2 << endl << endl;
   cout << "two" << endl;
   cout << m2t2 << endl << endl;
   
   cout << "one + two" << endl;
   cout << m1t2.addByReturningValue(m2t2) << endl;
   
   cout << "one - two" << endl;
   cout << m1t2.subByReturningValue(m2t2) << endl;
   
   cout << "one x two" << endl;
   cout << m1t2.mulByReturningValue(m2t2) << endl << endl;
   
   
   cout << "Test : operations that returns a pointer to a new Matrix :" << endl;
   const int MODT3 = 7;
   cout << "The modulus is " << MODT3 << endl << endl;
   Matrix m1t3(4,3,MODT3);
   Matrix m2t3(5,3,MODT3);
   
   cout << "one" << endl;
   cout << m1t3 << endl << endl;
   cout << "two" << endl;
   cout << m2t3 << endl << endl;
   
   cout << "one + two" << endl;
   cout << *(m1t3.addByReturningPointer(m2t3)) << endl;
   
   cout << "one - two" << endl;
   cout << *(m1t3.subByReturningPointer(m2t3)) << endl;
   
   cout << "one x two" << endl;
   cout << *(m1t3.mulByReturningPointer(m2t3)) << endl << endl;
   
   cout << "Error testing : " << endl;
   cout << "invalid Modulo given error (with -5 as modulus) :" << endl;
   try{
      Matrix me1t1(5,3,-5);
   }catch(const invalid_argument& e){
      cout << e.what() << endl << endl;
   }


   cout << "Operations on matrices with different modulus :" << endl;
   Matrix me1t2(4,3,3);
   Matrix me2t2(5,3,5);
   
   cout << "one with a modulus of 3" << endl;
   cout << me1t2 << endl << endl;
   
   cout << "two with a modulus of 5" << endl;
   cout << me2t2 << endl << endl;


   cout << "Test with const matrix" << endl;
   const Matrix m1Const(2,2,4);
   Matrix m2Const(3,3,4);
   m1Const.addByReturningValue(m2Const);

   try{
      me1t2.addByReturningValue(me2t2);
   }catch(const invalid_argument& e){
      cout << e.what() << endl;
   }

   return EXIT_SUCCESS;
}

