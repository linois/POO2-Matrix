/* ---------------------------
Laboratoire :  Labo 01 : Matrix Reloaded
Fichier     :  Matrix.h
Auteur(s)   :  Edouard de Chambrier, Valvona Guillaume
Date        :  27.02.2020

But         : Implémentation des méthodes définies dans le fichier Matrix.h

Compilateur :  MinGW-g++ 6.3.0
--------------------------- */

#include <sstream>
#include "Matrix.h"

Matrix::Matrix(size_t width, size_t height, size_t modulus):modulus(modulus), height(height),width(width) {
   // error if modulus is 0
   if(modulus <= 0){
      std::stringstream ss;
      ss << "modulus must be grater than 0 (" << modulus << ") given";
      throw std::invalid_argument(ss.str());
   }
   values = new int*[height];
   for(size_t i = 0; i<height; i++){
      values[i] = new int[width]; 
   }

   for(size_t i=0; i< height; i++ ){
      for(size_t j=0; j<width; j++){
      values[i][j] = rand() / (RAND_MAX + 1.0) * modulus;
      }
   }
}

Matrix::Matrix(const Matrix& other):modulus(other.modulus), height(other.height), width(other.width){
   copyTable(other.values);
}

Matrix::Matrix( int** const table, size_t width, size_t height, size_t modulus):height(height),width(width),modulus(modulus){
   copyTable(table);
}

Matrix::~Matrix(){
   for(size_t i =0; i< height; i++){
      delete[] values[i];
   } 
     delete[] values;
}

std::ostream& operator << (std::ostream& flux, const Matrix& matrix){
  for(size_t i = 0; i< matrix.height; i++){
     for(size_t j=0; j< matrix.width; j++){
        flux << matrix.values[i][j] << " ";
     }
     flux << std::endl;
  }
<<<<<<< HEAD

=======
>>>>>>> bc696471ea0ca2c9cc3abc3f45a3f356d2595479
  return flux;
}

Matrix& Matrix::operator=(const Matrix* matrix){
    this->width = matrix->width;
    this->height = matrix->height;
    this->modulus = matrix->modulus;

    copyTable(matrix->values);

    return *this;
}

// retourne une Matrix dont les valeur sont le sésultat de
// l'opétation (donnée en paramètre) des valeurs du tableau
// de la classe et de celui donnée en paramètre
/**
 *
 * @param other
 * @param op
 * @return
 */
Matrix Matrix::operation(const Matrix& other, const Operator& op) const{
   // Checks if both matrix have the same modulus
   if(this->modulus != other.modulus){
      throw std::invalid_argument("The modulus of both matrix must be the same.");
   }

   // find the biggest values of height and width of both of the matricxes
   int maxWidth = this->width > other.width ? this->width : other.width;
   int maxHeight = this->height > other.height ? this->height : other.height;

   // create the result matrix and assign the new values
   Matrix res(maxWidth, maxHeight, modulus);
   for(size_t i = 0; i<maxHeight;i++){
      for(size_t j = 0; j< maxWidth; j++){
         // basic way to get a positive modulus : (i % n + n) % n
         res.values[i][j] = ((op.apply(this->getValOrZero(i, j), other.getValOrZero(i,j)))%modulus + modulus)%modulus;
      }
   }
   return res;
}

Matrix& Matrix::modifyingMatrixOperations(Matrix& temp){
    height = temp.height;
    width = temp.width;
    std::swap(values, temp.values);
    return *this;
}

Matrix& Matrix::addByModifyingMatrix(const Matrix &other) {
    Matrix temp(addByReturningValue(other));
    return modifyingMatrixOperations(temp);
}

Matrix& Matrix::subByModifyingMatrix(const Matrix& other){
    Matrix temp(subByReturningValue(other));
    return modifyingMatrixOperations(temp);
}

Matrix& Matrix::mulByModifyingMatrix(const Matrix& other){
    Matrix temp(mulByReturningValue(other));
    return modifyingMatrixOperations(temp);
}

// si la position [i][j] du tableau existe, elle est retournée. Sinon retourne 0
int Matrix::getValOrZero(size_t i, size_t j) const{
   if(height > i && width > j){
      return values[i][j];
   }else{
      return 0;
   }
}

// création et remplissage du tableau de la classe
// à partir d'un taleau donné en paramètres
void Matrix::copyTable(int** const table){
   values = new int*[height];
   for(size_t i = 0; i<height; i++){
      values[i] = new int[width]; 
   }
   for(size_t i=0; i< height; i++ ){
      for(size_t j=0; j<width; j++){
      values[i][j] = table[i][j];
      }
   }
}
