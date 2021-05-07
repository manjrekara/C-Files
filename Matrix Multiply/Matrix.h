class Matrix {
public:
    Matrix(int);
    Matrix(int, char *);
    Matrix(const Matrix &);
    ~Matrix();
    Matrix operator * (Matrix&) const;
    void write(char *);
private:
    int size;
    double *data;
};


