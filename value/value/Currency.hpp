//
//  Currensy.hpp
//  value
//
//  Created by Misha Esherkin on 08/04/2019.
//  Copyright © 2019 Misha Esherkin. All rights reserved.
//

#pragma once

#include <iostream>

// тип валюты
enum class CurrencyType {
    dollar, euro, pound
};

class Currency {
protected:
    double value; // значение денежной единицы
    CurrencyType type; // тип валюты
    
public:
    virtual double ConvertToRub() const = 0; // виртуальный метод перевода в рубли
    virtual void Print() const = 0; // вывод на экран значения в рублях
    
    double GetValue() const; // получения значения валюты
    CurrencyType GetType() const; // получения типа валюты
};

class Dollar : public Currency {
public:
    Dollar(double value); // конструктор из значения в долларах
    
    double ConvertToRub() const; // перевод в рубли
    double ToCents() const; // перевод в центы
    
    void Print() const; // вывод
};

class Euro : public Currency {
public:
    Euro(double value); // конструктор из значения в евро
    
    double ConvertToRub() const; // перевод в рубли
    double ToCents() const; // перевод в центы
    
    void Print() const; // вывод
};

class Pound : public Currency {
public:
    Pound(double value); // конструктор из значения в фунтах стерлингов
    
    double ConvertToRub() const; // перевод в рубли
    double ToPenses() const; // перевод в пенсы
    
    void Print() const; // вывод
};
