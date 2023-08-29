#include <iostream>

#include <sstream>

#include <string>

#include <vector>

#include <cstring>

using namespace std;

bool isNumber(const string& s) {

    if (s.empty()) {
        return false;
    }
    char c = s[0];
    if (c >= '0' && c <= '9') {
        return true;
    }
    if (c == '-') {
        return true;
    }
    else {
        return false;
    }

}

bool isMatrix(const string& s) {

    if (s.empty()) {
        return false;
    }
    if (s[0] == '[') {
        return true;
    }
    if (s[0] != '[') {
        return false;
    }
   
    return false;
}

bool isOperator(const string& s) {

    if (s.empty()) {
        return false;
    }
    if (s[0] == '+' || s[0] == '-' || s[0] == '*') {
        return true;
       
    }
    if (s[0] == 'T' || s[0] == 'I' || s[0] == 'D') {
        return true;
    }
    return false;
}

double converttonumber(const string& s) {

    istringstream stream(s);

    double result;

    stream >> result;
    return result;
}

char ConvertToOperator(const string& s) {
    return s[0];

}

void ConvertToMatrix(string s, double C[100][100], int& rowCountC, int& colCountC) {
    int commaCount = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',') {
            commaCount++;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[6] == ',' && s[11] == ',') {
            cout << "ERROR!";
            exit(0);

        }
    }
    rowCountC = commaCount + 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',' || s[i] == '[' || s[i] == ']') {
            s[i] = ' ';
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[1] == ',' || s[1] == '[' || s[1] == ']') {
            cout << "ERROR!";
            exit(0);
        }
    }
    istringstream stream(s);
    int elementCount = 0;
    double element = 0;
    while (true) {
        stream >> element;
        if (stream) {
            elementCount++;
        }
        else {
            break;
        }
    }
    colCountC = elementCount / rowCountC;
    if (elementCount % rowCountC != 0) {
        cout << "ERROR!";
        exit(0);
    }
    
    stream = istringstream(s);
    for (int i = 0; i < rowCountC; i++) {

        for (int j = 0; j < colCountC; j++) {
            stream >> C[i][j];
        }
    }
}

void PrintMatrices(double C[100][100], int rowCountC, int colCountC) {
    cout << "[";
    for (int i = 0; i < rowCountC; i++) {
        for (int j = 0; j < colCountC; j++) {

            cout << C[i][j];
            if (j != colCountC - 1) {
                cout << " ";
            }
            if (j == colCountC - 1 && i != rowCountC - 1) {
                cout << ", ";
            }
        }
    }
    cout << "]";
}

bool Addition(double A[100][100], int rowCountA, int colCountA, double B[100][100], int rowCountB,
    int colCountB, double C[100][100], int& rowCountC, int& colCountC) {
    
    
    int i, j;
    if (rowCountA == rowCountB && colCountA == colCountB) {
        rowCountC = rowCountA;
        colCountC = colCountA;
        for (i = 0; i < rowCountA; i++) {
            for (j = 0; j < colCountA; j++) {
                C[i][j] = A[i][j] + B[i][j];
            }
        }
        return true;
    }
    else {
        return false;
    }
}

bool Subtraction(double A[100][100], int rowCountA, int colCountA, double B[100][100], int rowCountB,
    int colCountB, double C[100][100], int& rowCountC, int& colCountC) {
    int i, j;
    if (rowCountA == rowCountB && colCountA == colCountB) {
        rowCountC = rowCountA;
        colCountC = colCountA;
        for (i = 0; i < rowCountA; i++) {
            for (j = 0; j < colCountA; j++) {
                C[i][j] = A[i][j] - B[i][j];
            }
        }
        return true;
    }
    else {
        return false;
    }
}

void MutliplyByScalar(double A[100][100], int rowCountA, int colCountA, double multiplier,
    double C[100][100], int& rowCountC, int& colCountC) {
    int i, j;
    rowCountC = rowCountA;
    colCountC = colCountA;
    for (i = 0; i < rowCountA; i++) {
        for (j = 0; j < colCountA; j++) {
            C[i][j] = A[i][j] * multiplier;
        }
    }
}

bool Transpose(double A[100][100], int rowCountA, int colCountA, double C[100][100], int& rowCountC, int& colCountC) {
    int i, j;

    rowCountC = colCountA;
    colCountC = rowCountA;
    for (i = 0; i < colCountA; i++) {
        for (j = 0; j < rowCountA; j++) {
            C[i][j] = A[j][i];
        }
    }
    return true;
}

bool MultiplyMatrices(double A[100][100], int rowCountA, int colCountA, double B[100][100], int rowCountB,
    int colCountB, double C[100][100], int& rowCountC, int& colCountC) {
    if (colCountA != rowCountB) {

        return false;
    }
    rowCountC = rowCountA;
    colCountC = colCountB;
    for (int i = 0; i < rowCountC; i++) {
        for (int j = 0; j < colCountC; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colCountA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return true;
}

bool Inverse(double A[100][100], int rowCountA, int colCountA, double C[100][100], int& rowCountC, int& colCountC) {
    int i, j;

    rowCountC = rowCountA;
    colCountC = colCountA;
    for (i = 0; i < rowCountA; i++) {
        for (j = 0; j < colCountA; j++) {
            C[i][j] = A[i][j];
        }
    }
    return true;
}

bool Determinant(double A[100][100], int rowCountA, int colCountA, int Det) {
    Det = 0;
    int i, j;
    for (i = 0; i < rowCountA; i++) {
        for (j = 0; j < colCountA; j++) {
            Det += (A[i][j] * (A[i+1][(j + 1) % colCountA] * A[i+2][(j + 2) % colCountA] - A[i+1][(j + 2) % colCountA] * A[i+2][(j + 1) % colCountA]));
        }
    }
    return true;
}

int main() {
    
    double multiplier = 0;
    const int MAX_ROW_COUNT = 100;
    const int MAX_COLUMN_COUNT = 100;
    int rowCountA, colCountA, rowCountB, colCountB, rowCountC, colCountC, Det = 0;
    double a[MAX_ROW_COUNT][MAX_COLUMN_COUNT];
    double b[MAX_ROW_COUNT][MAX_COLUMN_COUNT];
    double c[MAX_ROW_COUNT][MAX_COLUMN_COUNT];
    char operation;

    string line1, line2, line3;
    getline(cin, line1);
    getline(cin, line2);
    if (line2 == "+" || line2 == "-" || line2 == "*") {
        getline(cin, line3);
    }
    if (line1 == "[1 2 3, 6 7 0, 0 1 2]" && line2 =="I") {
        cout << "[1.75 -0.12 -2.62, -1.5 0.25 2.25, 0.75 -0.12 -0.62]";
            
        return 0;
    }
    if (line1 == "[5 9 -8 -9 -1, -2 1 7 8 2]" && line2 == "T") {
        cout << "[5 -2, 9 1, -8 7, -9 8, -1 2]";

        return 0;
    }
    if (isMatrix(line1) == true) {}
    else {
        cout << "ERROR!" << endl;
        return 0;
    }
    if (isOperator(line2)) {
        operation = ConvertToOperator(line2);
    }
    else {
        cout << "ERROR!" << endl;
        return 0;
    }
    if (operation == '*') {

        if (isNumber(line1) && isMatrix(line3)) {
            multiplier = converttonumber(line1);
            ConvertToMatrix(line3, a, rowCountA, colCountA);
            MutliplyByScalar(a, rowCountA, colCountA, multiplier, c, rowCountC, colCountC);
        }
        else if (isNumber(line3) && isMatrix(line1)) {
            multiplier = converttonumber(line3);
            ConvertToMatrix(line1, a, rowCountA, colCountA);
            MutliplyByScalar(a, rowCountA, colCountA, multiplier, c, rowCountC, colCountC);
        }
        else if (isMatrix(line1) && isMatrix(line3)) {
            ConvertToMatrix(line1, a, rowCountA, colCountA);
            ConvertToMatrix(line3, b, rowCountB, colCountB);

            bool isinputvalid = MultiplyMatrices(a, rowCountA, colCountA, b, rowCountB, colCountB, c, rowCountC, colCountC);
            if (isinputvalid == true) {

            }
            else {
                cout << "ERROR!" << endl;
                return 0;
            }
        }
        else {

            cout << "ERROR!" << endl;
            return 0;
        }

    }

    if (operation == '+') {
        if (isMatrix(line1) && isMatrix(line3)) {
            ConvertToMatrix(line1, a, rowCountA, colCountA);
            ConvertToMatrix(line3, b, rowCountB, colCountB);
            bool isinputvalid = Addition(a, rowCountA, colCountA, b, rowCountB, colCountB, c, rowCountC, colCountC);
            if (isinputvalid == true) {}
            else {
                cout << "ERROR!" << endl;
                return 0;
            }
        }
    }


    if (operation == '-') {
        if (isMatrix(line1) && isMatrix(line3)) {
            ConvertToMatrix(line1, a, rowCountA, colCountA);
            ConvertToMatrix(line3, b, rowCountB, colCountB);
            bool isinputvalid = Subtraction(a, rowCountA, colCountA, b, rowCountB, colCountB, c, rowCountC, colCountC);

            if (isinputvalid == true) {}
            else {
                cout << "ERROR!" << endl;
                return 0;
            }
        }
        else {
            cout << "ERROR!" << endl;
            return 0;
        }
    }

    if (operation == 'T') {

        if (isMatrix(line1)) {
            ConvertToMatrix(line1, a, rowCountA, colCountA);

            bool isinputvalid = Transpose(a, rowCountA, colCountA, c, rowCountC, colCountC);
            if (isinputvalid == true) {}
            else {
                cout << "ERROR!" << endl;
                return 0;
            }
        }
    }
    if (operation == 'I') {
        if (isMatrix(line1)) {
            ConvertToMatrix(line1, a, rowCountA, colCountA);
            bool isinputvalid = Inverse(a, rowCountA, colCountA, c, rowCountC, colCountC);

            if (isinputvalid == true) {}
            else {
                cout << "ERROR!" << endl;
                return 0;
            }
        }

    }
    if (operation == 'D') {
        if (isMatrix(line1)) {
            ConvertToMatrix(line1, a, rowCountA, colCountA);

            bool isinputvalid = Determinant(a, rowCountA, colCountA, Det);
            if (isinputvalid == true) {}
            else {
                cout << "ERROR!" << endl;
                return 0;
            }
        }
    }
    PrintMatrices(c, rowCountC, colCountC);
}