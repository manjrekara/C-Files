#include <string>
#include <iostream>

using namespace std;

class Vector {
public:
    Vector(int, float *);
    Vector(const Vector &);
    ~Vector();
    Vector operator * (Vector &);
    
    Vector operator * (float);
    Vector operator + (Vector &);
    
    float operator [] (int) const;
    void print();
    int sizeOf() {return size;}
    
private:
    float *data;
    int size;
};

class myVector : public Vector {
public:
    myVector(const Vector &);
    void print();
};
    
Vector::Vector(int s, float *d)
    : size(s)
{
    data = new float[size];
    for (int i=0; i<size; i++) {
        data[i] = d[i];
    }
}

Vector::Vector(const Vector &v)
    : size(v.size)
{
    data = new float[size];
    for (int i=0; i<size; i++) {
        data[i] = v[i];
    }
}

Vector::~Vector(){
    delete [] data;
}

Vector Vector::operator *(Vector &v){
    Vector r(size, data);

    for (int i=0; i<size; i++) {
        r.data[i] = data[i] * v[i];
    }

    return r;
}

Vector Vector::operator +(Vector &v){
    Vector r(size, data);

    for (int i=0; i<size; i++) {
        r.data[i] = data[i] + v[i];
    }
    return r;
}

Vector Vector::operator *(float n){
    Vector r(size, data);

    for (int i=0; i<size; i++) {
        r.data[i] = data[i] * n;
    }
    return r;
}

float Vector::operator [] (int i) const{
    return data[i];
}

void Vector::print(){
    for (int i=0; i<size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

myVector::myVector(const Vector &v)
    : Vector(v)
{
}

void myVector::print(){
    for (int i=0; i<sizeOf(); i++) {
        cout << (*this)[i] << endl;
    }
    cout << endl;
}

int main(){
    float data1[] = {1,2,3};
    float data2[] = {3,4,5};

    Vector a(3, data1);
    Vector b(3, data2);

    Vector c = a * b;
    Vector d = a + b;
    Vector e = a * 4;

    c.print();
    d.print();
    e.print();
}