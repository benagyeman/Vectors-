#ifndef VECTORHEADERFILE
#define VECTORHEADERFILE 

class Vector
{
    private:
    double* mData; // This refers to the data stored in the vector.
    int mSize; // This denotes the size of the vector

    public:
    Vector(const Vector& otherVector); //A copy constructor, const ensures that the constructor does not alter the contents of "other vector"
    Vector(int size); // A constructor
    ~Vector(); // A destructor
    int GetSize() const;

    double& operator[] (int i); // This implements the zero-based indexing

    double Read(int i) const;
    double& operator() (int i) const; //This implements the one-based indexing

    //Operator overloading, all these return an instance of the vector class. The arguments are passed as reference since we basically want to access the values that the arguments hold
    // The const keyword ensures that the methods do not alter the arguments
    Vector& operator=(const Vector& otherVector); // Overloading the assignment operator
    Vector operator+() const; // unary addition
    Vector operator-() const; // unary subtraction 
    Vector operator+(const Vector& v1) const; // binary addition
    Vector operator-(const Vector& v1) const; // binary subtraction
    Vector operator*(double a) const; // Scalar multiplication

    double CalculateNorm(int p=2) const; // Calculate the 2-norm of the vector

    friend int length(const Vector& v);

};

int length(const Vector& v);

#endif 
