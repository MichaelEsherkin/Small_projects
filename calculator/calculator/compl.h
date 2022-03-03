//
//  Header.h
//  calculator
//
//  Created by Misha Esherkin on 11/03/2019.
//  Copyright © 2019 Misha Esherkin. All rights reserved.
//

#ifndef compl_h
#define compl_h

#pragma once

#include <iostream>
#include <fstream>
#include <cmath>

class Complex {
private:
    double re; // Действительная часть
    double im; // Мнимая часть
    
public:
    Complex(double re = 0, double im = 0); // конструктор (с двумя параметрами, с одним и по умолчанию)
    double abs(); // Модуль комплексного числа
    void root(std::ofstream& f); // корень из числа
    
    Complex operator+(const Complex &); // Перегрузка оператора сложения
    Complex operator-(const Complex &); // Перегрузка оператора вычитания
    Complex operator*(const Complex &); // Перегрузка оператора умножения
    Complex operator/(const Complex &); // Перегрузка оператора деления
    Complex operator++(int); // унарный плюс
    Complex operator--(int); // унарный минус
    
    friend std::ostream& operator<<(std::ostream &, Complex &); // Перегрузка оператора << для вывода
    friend std::istream& operator>>(std::istream &, Complex &); // Перегрузка оператора >> для ввода Complex
};


#endif /* compl_h */
