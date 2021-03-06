/** @author Siddhant Parekh*/

#ifndef MATRIX_LIBRARY_HPP
#define MATRIX_LIBRARY_HPP

#define VERBOSE false
#define CONDITIONAL_PRINT if(VERBOSE) cout

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
using namespace std;

/**
 * A library to perform operations on matrices.
 */
class Matrix
{
private:

    /**
     * @var rows is a private data member which contains the number of rows of the matrix.
     * @var cols is a private data member which contains the number of columns of the matrix.
     */
    ulong rows, cols;

    /** **matrix is a private data member which points to a 2D array which contains the matrix elements.*/
    double **matrix;


    /**
     * @brief A member function to set rows and columns of the object.
     * @param rows contains the rows to be set.
     * @param cols contains the columns to be set.
     */
    void setDimensions(ulong rows, ulong cols);

    /**
     * @brief Allocates memory to the 2D array matrix.
     */
    void allocateMemory();

    /**
     * @brief Deallocates the memory of the 2D array matrix.
     */
    void deallocateMemory();


public:
    /**
     * @brief Default constructor.
     * @details Initialises values of rows and cols to 0.
     */
    Matrix();

    /**
     * @brief Parameterized constructor.
     * @details Memory is allocated to the member **matrix pointer.
     * The matrix elements are initialized to 0.
     * @param rows is of the type unsigned long, used to initialise the member rows.
     * @param cols is of the type unsigned long, used to initialise the member cols.
     */
    Matrix(ulong rows, ulong cols);

    /**
     * @brief Copy constructor.
     * @details The contents of the object received in the argument list are copied to the current objects memory.
     * @param matrixToBeCopied is a reference to another object of the Matrix class.
     */
    Matrix(const Matrix &matrixToBeCopied);

    /** @brief Destructor. */
    virtual ~Matrix();

    /**
     * @brief Getter for member rows.
     * @return Rows of the matrix.
     */
    ulong getRows();

    /**
     * @brief Getter for member cols.
     * @return Columns of the matrix.
     */
    ulong getCols();

    /**
     * @brief Checks whether the matrix exists.
     * @return boolean value true if exists else false.
     */
    bool exists() const;

    /** @brief Display the matrix.*/
    void displayMatrix();

    /** @brief Assigns random values to the matrix if exists.*/
    void generateRandomMatrix();

    /**
     * @brief Reads a matrix from a file.
     *
     * @param fname contains the file name from which the matrix is to be read.
     */
    void readMatrixFromFile(const string &fname);

    /**
     * @brief Writes the matrix to the file.
     *
     * @param fname contains the file name to which the matrix is to be written.
     */
    void writeMatrixToFile(const string &fname);

    /**
     * @overload '=' to assign elements of one matrix to another.
     * @param matrixToBeAssigned is a reference to another object of the Matrix class.
     */
    Matrix& operator=(const Matrix &matrixToBeAssigned);

    /**
     * @overload '+' to add two matrices.
     * @param matrixToBeAdded is a reference to the object to be added.
     * @attention The two matrix objects are supposed to be of the same dimension.
     * @return Matrix object which contains sum of the matrices.
     */
    Matrix operator+(const Matrix &matrixToBeAdded) const;

    /**
     * @overload '-' to get the difference between two matrices.
     * @param matrixToBeSubtracted is a reference to the object to be subtracted.
     * @attention The two matrix objects are supposed to be of the same dimension.
     * @return Matrix object which contains difference of the matrices.
     */
    Matrix operator-(const Matrix &matrixToBeSubtracted) const;

    /**
     * @overload '*' to multiply the matrix by a scalar.
     * @param scalar is a value by which the matrix is to be multiplied.
     * @return Matrix object which contains the modified matrix.
     */
    Matrix operator*(double scalar) const;

    /**
     * @overload '*' to get the product of two matrices.
     * @param matrixToBeMultiplied is a reference to the object to be multiplied.
     * @attention rows of matrix 1 are supposed to be equal to the columns of matrix 2 or vice-versa.
     * @return Matrix object having the product of the two matrices.
     */
    Matrix operator*(const Matrix &matrixToBeMultiplied) const;

    /**
     * @brief Checks whether the matrix is a square matrix.
     * @return true if square matrix else false.
     */
    bool isSquareMatrix() const;

    /**
     * @brief Checks whether the matrix is an identity matrix.
     * @return true if identity else false.
     */
    bool isIdentityMatrix() const;

    /**
     * @brief Checks whether the matrix is a symmetric matrix.
     * @return true if symmetric matrix else false.
     */
    bool isSymmetricMatrix() const;

    /**
     * @brief Checks whether the matrix is a NULL matrix.
     * @return true if NULL matrix else false.
     */
    bool isNullMatrix() const;

    /**
     * @brief Checks whether the matrix is a diagonal matrix.
     * @return true if diagonal matrix else false.
     */
    bool isDiagonalMatrix() const;

    /**
     * @brief Checks whether the matrix is diagonally dominant.
     * @return true if it is diagonally dominant else false.
     */
    bool isDiagonallyDominant() const;

    /**
     * @brief Checks whether the matrix is orthogonal.
     * @return true if orthoganal else false.
     */
    bool isOrthogonal() const;

    /**
     * @brief Calculates the trace of the matrix.
     * @return Trace of the matrix.
     */
    double traceOfMatrix() const;

    /**
     * @brief Gives the transpose of a given matrix.
     * @return a Matrix object which is the transpose of the calling matrix.
     */
    Matrix transpose() const;

    /**
     * @brief Augments given matrices
     * @param A is a reference to the coefficient matrix
     * @param B is a reference to the constant matrix
     * @return An augmented matrix.
     */
    friend Matrix augmentMatrices(const Matrix &A, const Matrix &B);

    /** @brief swap two rows.*/
    void interchangeRows(ulong r1, ulong r2);

    /**
     * @brief Interchange the rows of the calling matrix.
     * @param rowToBeInterchanged is the row number which is to be replaced.
     * @details A row below the rowToBeInterchanged is searched whose diagonal element for the rowToBeInterchanged is non-zero
     * and replaced with the rowToBeInterchanged.
     */
    void pivotMatrix(ulong rowToBeInterchanged);

    /**
     * @brief Solves a given matrix to find the solution by back substitution.
     * @attention The function assumes the matrix is an upper triangular matrix.
     * @return A solution matrix.
     */
    Matrix backSubstitution() const;

    /**
     * @brief Factorizes a given matrix into product of Lower and Upper triangular matrices.
     * @details The diagonal elements of the lower triangular matrix are non-zero.
     * The diagonal elements of the upper triangular matrix are '1'.
     * @return An augmented matrix whose Upper triangular elements is the upper triangular matrix and the diagonals are '1'
     * and Lower triangular elements is the lower triangular matrix including the diagonal elements.
     */
    Matrix triangularFactorizationCrouts();

    /**
     * @brief Solves the given system of linear equations using LU decomposition/Triangular Factorization.
     * @return a Matrix object (vector) containing the solution which satisfies the system.
     */
    Matrix solveTriangularMatrix() const;

    /**
     * @brief Solves the given system of linear equations using gaussian elimination.
     * @return a Matrix object (vector) containing the solution which satisfies the system.
     */
    Matrix gaussianElimination() const;

    /**
     * @brief Solves the given system of linear equations using Gauss Seidel.
     * @return a Matrix object (vector) containing the solution which satisfies the system.
     */
    Matrix gaussSeidel() const;

    /**
     * @brief Solves the given system of linear equations using Gauss Jacobi.
     * @return a Matrix object (vector) containing the solution which satisfies the system.
     */
    Matrix gaussJacobi() const;

    /**
     * @brief Compares given matrices
     * @param rop is the right hand side matrix
     * @return true if matrices are equivalent else false
     */
    bool operator==(const Matrix &rop) const;

    /**
     * @brief Easier access to matrix elements
     * @param index is the row number i.e. the first parameter
     * @return a reference to a pointer of a row
     */
    double*& operator[](ulong index) const;

    /**
     * @brief Computes all possible two minors and finds a zero in the Matrix
     * @return Position of the zero
     */
    Matrix find_zero() const;
};

#endif