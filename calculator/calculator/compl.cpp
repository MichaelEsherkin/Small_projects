//
//  compl.cpp
//  calculator
//
//  Created by Misha Esherkin on 11/03/2019.
//  Copyright © 2019 Misha Esherkin. All rights reserved.
//

#include "compl.h"

using namespace std;

Complex::Complex(double re, double im) {
    this->re = re;
    this->im = im;
}

double Complex::abs() {
    return sqrt(re * re + im * im);
}

void Complex::root(ofstream& f) {
    double m = sqrt(re * re + im * im);
    
    Complex z1, z2;
    
    z1.im = sqrt((-re + m) / 2);
    z1.re = im / (2 * z1.im);
    
    z2.re = -z1.re;
    z2.im = -z1.im;
    
    cout << "root1:" << z1 << endl;
    cout << "root2:" << z2 << endl;
    
    f << "root1:" << z1 << endl;
    f << "root2:" << z2 << endl;
}

// Перегрузка +
Complex Complex::operator+(const Complex &c) {
    return Complex(re + c.re, im + c.im);
}

// Перегрузка -
Complex Complex::operator-(const Complex &c) {
    return Complex(re - c.re, im - c.im);
}

// Перегрузка *
Complex Complex::operator*(const Complex &c) {
    return Complex(re * c.re - im * c.im, re * c.im + c.re * im);
}

// Перегрузка /
Complex Complex::operator/(const Complex &c) {
    double k = c.re * c.re + c.im * c.im;
    Complex res;
    
    res.re = (re * c.re + im * c.im) / k;
    res.im = (c.re * im - re * c.im) / k;
    
    return res;
}

// унарный плюс
Complex Complex::operator++(int) {
    return Complex(re, im);
}

// унарный минус
Complex Complex::operator--(int) {
    return Complex(-re, -im);
}

// Перегрузка оператора <<
ostream& operator<< (ostream &os, Complex &c) {
    if (c.im < 0) {
        os << c.re << "+i(" << c.im << ")";
    }
    else {
        os << c.re << "+i" << c.im;
    }
    
    return os;
}

// Перегрузка оператора >>
istream &operator>>(istream &is, Complex &c) {
    cout << "Enter re: ";
    is >> c.re;
    cout << "Enter im: ";
    is >> c.im;
    
    return is;
}
