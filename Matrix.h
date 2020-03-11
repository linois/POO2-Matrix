/* ---------------------------
Laboratoire :  Labo 01 : Matrix Reloaded
Fichier     :  Matrix.h
Auteur(s)   :  Edouard de Chambrier, Valvona Guillaume
Date        :  27.02.2020

But         : Header de la classe Matrix
              Contient la définition de toutes les méthodes employées dans
              la classe Matrix
  
Remarque(s) : -

Compilateur :  MinGW-g++ 6.3.0
--------------------------- */

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "operators.h"

class Matrix{
private :
    size_t modulus;
    size_t height;
    size_t width;
   
    int **values;
   
public :
    /**
     * Basic contructor
     *
     * @param width     : width of the matrix
     * @param height    : height of the matrix
     * @param modulus   : modulus of the matrix
     */
    Matrix(size_t width, size_t height, size_t modulus);

    /**
     * Default contructor, all values set to 0
     */
    Matrix():Matrix(0,0,1){}

    /**
     * Copy constructor
     *
     * @param other     : Matrix to copy
     */
    Matrix(const Matrix& other);

    /**
     * Constructor with table given.
     *
     * @param table     : table of the matrix
     * @param height    : height of the matrix
     * @param width     : width of the matrix
     * @param modulus   : modulus of the matrix
     */
    Matrix(int** const table, size_t height, size_t width, size_t modulus);

    /**
     * Destructor
     */
    virtual ~Matrix();

    friend std::ostream& operator << (std::ostream& flux, const Matrix& matrix);

    Matrix& operator=(const Matrix* matrix);

    /**
     * Operation applied to the Matrix
     *
     * @param other     : Matrix which the operation applies to
     * @param op        : operation to apply
     * @return          : a new Matrix
     */
    Matrix operation(const Matrix& other, const Operator& op) const;

    /**
     * Adds 2 matrix by modifying the matrix other
     * @param other the matrix we want to add
     * @return a new matrix which is the sum of our matrix and other
     */
    Matrix& addByModifyingMatrix(const Matrix& other);

    /**
     * Substracts 2 matrix by modifying the matrix other
     * @param other the matrix we want to sub
     * @return a new matrix which is the difference of our matrix and other
     */
    Matrix& subByModifyingMatrix(const Matrix& other);

    /**
     * Multiplies 2 matrix by modifying the matrix other
     * @param other the matrix we want to add
     * @return a new matrix which is the product of our matrix and other
     */
    Matrix& mulByModifyingMatrix(const Matrix& other);

    /**
     * Adds 2 matrix by returning a value
     * We can't return a reference because at the end of the function, object is deleted
     * @param other the matrix we want to add
     * @return a new matrix, created in operation
     */
    Matrix addByReturningValue(const Matrix& other) const{
        Add op;
        return operation(other, op);
    }

    /**
     * Substracts 2 matrix by returning a value
     * We can't return a reference because at the end of the function, object is deleted
     * @param other the matrix we want to substract
     * @return a new matrix, created in operation
     */
    Matrix subByReturningValue(const Matrix& other) const{
        Sub op;
        return operation(other, op);
    }

    /**
     * Multiplies 2 matrix by returning a value
     * We can't return a reference because at the end of the function, object is deleted
     * @param other the matrix we want to multiply
     * @return a new matrix, created in operation
     */
    Matrix mulByReturningValue(const Matrix& other) const{
        Mul op;
        return operation(other, op);
    }

    /**
     * Adds 2 matrix by returning a pointer on a result matrix
     * @param other the matrix we want to add
     * @return a pointer on a matrix
     */
    Matrix* addByReturningPointer(const Matrix& other) const{
        return new Matrix(addByReturningValue(other));
    }

    /**
     * Substracts 2 matrix by returning a pointer on a result matrix
     * @param other the matrix we want to substract
     * @return a pointer on a matrix
     */
    Matrix* subByReturningPointer(const Matrix& other) const{
        return new Matrix(subByReturningValue(other));
    }

    /**
     * Multiplies 2 matrix by returning a pointer on a result matrix
     * @param other the matrix we want to multiply
     * @return a pointer on a matrix
     */
    Matrix* mulByReturningPointer(const Matrix& other) const{
        return new Matrix(mulByReturningValue(other));
    }
   
private:
    int getValOrZero(size_t i, size_t j) const;
    void copyTable(int** const table);
};

std::ostream& operator << (std::ostream& flux, const Matrix& matrix);

#endif /* MATRIX_H */

