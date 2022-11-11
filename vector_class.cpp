#include <cmath>
#include <iostream>
#include <cassert>
#include "vector_class.hpp"

using namespace std;

// This block overrides the default copy constructor. 
// Allocates memory for a new vector, and copies the entries of the other vector into it
Vector::Vector(const Vector& otherVector)
{
    mSize = otherVector.GetSize(); // Get the size of the other vector
    mData = new double [mSize]; // Allocate memory for the new vector

    for (int i = 0; i<mSize; i++)
    {
        mData[i] = otherVector.mData[i]; // Copy the entries of the other vector into the new vector
    }
}

//Constructor for vector of a given size
//Allocates memory and sets the entries to zero

Vector::Vector(int size)
{
    assert(size > 0);
    mSize = size;

    mData = new double [mSize];

    for( int i=0; i<mSize; i++)
    {
        mData[i] = 0.0;
    }
}

// Overriden destructor to correctly free the allocated memory

Vector::~Vector()
{
    delete[] mData;
}


int Vector::GetSize() const
{
    return mSize;
}

//Overloading square brackets
// This uses the zero-based indexing and it checks the validity of the index

double& Vector::operator[] (int i) // This can be used to change the entries of the vector because it returns a reference
{
    assert (i>-1);

    assert(i<mSize);

    return mData[i]; // For this to work, mData should be a global variable. I surmise that since the method can access the member mData, this code will work fine
}

// The read only variant of []
double Vector::Read(int i) const 
{
    assert (i>-1);
    assert(i<mSize);

    return mData[i];
}

//Overloading round brackets and this one uses the one based indexing.
// Also checks the validity of the index.Indexing in matlab starts from 1.

double& Vector::operator() (int i) const
{
    assert(i >0);
    assert(i<mSize+1);

    return mData[i-1];
}

// Overloading the assignment operator

Vector& Vector::operator=(const Vector& otherVector)
{
    assert(mSize==otherVector.mSize);

    for (int i=0; i<mSize; i++)
    {
        mData[i] = otherVector.mData[i];
    }

    return *this;
}

// Overloading the unary + operator
 Vector Vector::operator+() const
 {
     Vector v(mSize);

     for (int i=0; i<mSize;i++)
     {
         v[i] = mData[i];
     }

     return v;
 }


// Overloading the unary - operator
 Vector Vector::operator-() const
 {
     Vector v(mSize);

     for (int i=0; i<mSize;i++)
     {
         v[i] = -mData[i];
     }

     return v;
 }

 //Overloading the binary + operator
 Vector Vector::operator+(const Vector& v1) const
 {
     assert(mSize==v1.mSize);
     Vector v(mSize);

     for (int i=0; i<mSize;i++)
     {
         v[i] = mData[i] + v1.mData[i];
     }

     return v;
 }

//Overloading the binary - operator
 Vector Vector::operator-(const Vector& v1) const
 {
     assert(mSize==v1.mSize);
     Vector v(mSize);
     

     for (int i=0; i<mSize;i++)
     {
         v[i] = mData[i] - v1.mData[i];
     }

     return v;
 }

 //Overload the scalar multiplication data

 Vector Vector::operator*(double a) const 
 {
     Vector v(mSize);

     for (int i=0; i<mSize; i++)
     {
         v[i] = a*mData[i];
     }

     return v;
 }

 // Method to compute the 2 norm of the vector

 double Vector::CalculateNorm(int p) const 
 {
     double norm_val, sum_val = 0.0;

     for (int i=0; i<mSize; i++)
     {
         sum_val += pow(fabs(mData[i]), p);
     }

     norm_val = pow(sum_val, 1/((double) p));

     return norm_val;
 }

 //A MATLAB style friend function to get the size if a vector

int length(const Vector& v)
{
    return v.mSize;
}