//
//  purse.hpp
//  value
//
//  Created by Misha Esherkin on 08/04/2019.
//  Copyright © 2019 Misha Esherkin. All rights reserved.
//

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Currency.hpp"

class Purse {
    Currency **currencies; // валюты
    int size; // размер массива валют
    int capacity; // ёмкость массива валют
    
public:
    Purse(); // конструктор по умолчанию
    
    void PrintAmount() const; // вывод общей суммы в рублях
    void PrintByCurrency() const; // вывод суммы по каждой валюте
    
    void AddCurrency(Currency *currency); // добавление валюты
    void Sort(); // сортировка по возрастанию валюты в рублях
    void SaveToFile(const std::string& path) const; // сохранение в файл
    void ReadFromFile(const std::string& path); // чтение из файла
    
    ~Purse(); // деструктор, освобождение памяти
};

using namespace std;

