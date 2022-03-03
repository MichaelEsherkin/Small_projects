//
//  Currensy.cpp
//  value
//
//  Created by Misha Esherkin on 08/04/2019.
//  Copyright © 2019 Misha Esherkin. All rights reserved.
//

#include "Currency.hpp"


using namespace std;

// получения типа валюты
CurrencyType Currency::GetType() const {
    return type;
}

// получения значения валюты
double Currency::GetValue() const {
    return value;
}

// конструктор из значения в долларах
Dollar::Dollar(double value) {
    this->value = value;
    this->type = CurrencyType::dollar;
}

// конструктор из значения в евро
Euro::Euro(double value) {
    this->value = value;
    this->type = CurrencyType::euro;
}

// конструктор из значения в фунтах стерлингов
Pound::Pound(double value) {
    this->value = value;
    this->type = CurrencyType::pound;
}

// перевод долларов в рубли
double Dollar::ConvertToRub() const {
    return 63.78 * value;
}

// перевод евро в рубли
double Euro::ConvertToRub() const {
    return 71.71 * value;
}

// перевод фунтов стерлингов в рубли
double Pound::ConvertToRub() const {
    return 82.88 * value;
}

// вывод долларов в рублях
void Dollar::Print() const {
    cout << value << " USD = "<< ConvertToRub() << " RUB" << endl;
}

// вывод евро в рублях
void Euro::Print() const {
    cout << value << " EUR = "<< ConvertToRub() << " RUB" << endl;
}

// вывод евро в рублях
void Pound::Print() const {
    cout << value << " GBP = "<< ConvertToRub() << " RUB" << endl;
}

// перевод в центы
double Dollar::ToCents() const {
    return value * 100;
}

// перевод в центы
double Euro::ToCents() const {
    return value * 100;
}

// перевод в пенсы
double Pound::ToPenses() const {
    return value * 100;
}
