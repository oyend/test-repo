// 김지우 202500981 컴퓨터공학부
// Touched by user2(nf-25)

#include <iostream>

using namespace std;

class Matrix { 
    private:
        int r, c; 
        int** arr; 
    public:
        Matrix() : r(0), c(0), arr(NULL) {};
        Matrix(int r, int c); 
        Matrix(const Matrix& a); 
        ~Matrix();
        Matrix& operator=(const Matrix& a);
        void input();
        void print() const; 
        Matrix add(const Matrix& a); 
        Matrix subtract(const Matrix& a);
        Matrix transpose(); 
};

Matrix::Matrix(int r, int c) : r(r), c(c) { 
    arr = new int*[r]; 
    for (int i = 0; i < r; i++) arr[i] = new int[c];
}

Matrix::Matrix(const Matrix& a) : r(a.r), c(a.c) {
    arr = new int* [r];
    for (int i = 0; i < r; i++) arr[i] = new int[c]; 
    for (int i = 0; i < r; i++) { 
        for (int j = 0; j < c; j++) {
            arr[i][j] = a.arr[i][j];
        }
    }

}

Matrix::~Matrix() { 
    if (arr != NULL) {
        for (int i = 0; i < r; i++) delete[] arr[i];
        delete[] arr;
    }
}

Matrix& Matrix::operator=(const Matrix& a) {
    if (this == &a) return *this;
    if (arr != NULL) {
        for (int i = 0; i < r; i++) delete[] arr[i];
        delete[] arr;
    }
    r = a.r;
    c = a.c;
    arr = new int* [r];
    for (int i = 0; i < r; i++) arr[i] = new int[c];
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) arr[i][j] = a.arr[i][j];
    return *this;
}

void Matrix::input() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j]; 
        }
    }

}

void Matrix::print() const {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout <<  arr[i][j] << " "; 
        }
        cout << endl; 
    }

}

Matrix Matrix::add(const Matrix& a) {
    Matrix result(r, c); 
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
        result.arr[i][j] = arr[i][j] + a.arr[i][j]; 
        }
    }
    return result;
}

Matrix Matrix::subtract(const Matrix& a) {
    Matrix result(r, c); 
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
        result.arr[i][j] = arr[i][j] - a.arr[i][j]; 
        }
    }
    return result; 
}

Matrix Matrix::transpose() {
    Matrix result(c, r); 
    for (int i = 0; i < result.r; i++) {
        for (int j = 0; j < result.c; j++) {
            result.arr[i][j] = arr[j][i]; 
        }
    }
    return result;
}

int main() { 
    int op, r, c;
    bool yn = true;
    while (yn) {
        cout << "원하는 연산을 선택하세요.(1: 덧셈, 2: 뺄셈, 3: 전치) ";
        cin >> op;
        cout << endl;
        cout << "원하는 행렬의 크기를 입력하세요. ";
        cin >> r >> c;
        cout << endl;
        if (op == 1) {
            Matrix A(r, c), B(r, c);
            cout << "행렬 A의 원소 입력: " << endl;
            A.input();
            cout << "행렬 B의 원소 입력: " << endl;
            B.input();
            cout << endl;
            cout << "행렬 A:" << endl;;
            A.print();
            cout << "행렬 B:" << endl;;
            B.print();
            cout << "A+B:" << endl;
            A.add(B).print();
        }
        else if (op == 2) {
            Matrix A(r, c), B(r, c);
            cout << "행렬 A의 원소 입력: " << endl;
            A.input();
            cout << "행렬 B의 원소 입력: " << endl;
            B.input();
            cout << endl;
            cout << "행렬 A:" << endl;;
            A.print();
            cout << "행렬 B:" << endl;;
            B.print();
            cout << "A-B:" << endl;
            A.subtract(B).print();
        }
        else if (op == 3) {
            Matrix A(r, c);
            cout << "행렬의 원소 입력: " << endl;
            A.input();
            cout << endl;
            cout << "행렬:" << endl;;
            A.print();
            cout << "A의 전치:" << endl;
            A.transpose().print();
        }
        else {
            cout << "올바르지 않은 입력입니다." << endl;
        }
        cout << "연산을 계속하실거면 1, 연산을 종료할 거면 0을 눌러주세요. ";
        cin >> yn;
        if (!yn) cout << "연산을 종료합니다." << endl;
    }
    return 0;   
}

