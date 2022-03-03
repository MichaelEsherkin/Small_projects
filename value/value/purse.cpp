//
//  purse.cpp
//  value
//
//  Created by Misha Esherkin on 08/04/2019.
//  Copyright © 2019 Misha Esherkin. All rights reserved.
//

#include "purse.hpp"

// конструктор по умолчанию
Purse::Purse() {
    currencies = new Currency*[1]; // выделяем память под массив указателей
    size = 0; // изначально нет объектов
    capacity = 1; // доступно место под 1 элемент
}

// добавление валюты
void Purse::AddCurrency(Currency *currency) {
    currencies[size++] = currency; // добавляем в массив
    
    if (size >= capacity) {
        capacity *= 2; // увеличиваем ёмкость массива в два раза
        
        Currency** tmp = new Currency*[capacity]; // выделяем память под новый массив с большим размером
        
        for (int i = 0; i < size; i++)
            tmp[i] = currencies[i]; // копируем каждый элемент в новый массив
        
        delete[] currencies; // освобождаем память из-под прошлого массива
        
        currencies = tmp; // подменяем указатель на массив
    }
}

// сортировка по возрастанию валюты в рублях
void Purse::Sort() {
    bool isSorted = false;
    
    while (!isSorted) {
        isSorted = true; // считаем, что отсортировано
        
        // сортируем
        for (int i = 0; i < size - 1; i++) {
            if (currencies[i]->ConvertToRub() > currencies[i + 1]->ConvertToRub()) {
                // меняем местами сосдение элементы
                Currency *tmp = currencies[i];
                currencies[i] = currencies[i + 1];
                currencies[i + 1] = tmp;
                isSorted = false; // ещё пока не отсортировано
            }
        }
    }
}

// сохранение в файл
void Purse::SaveToFile(const string& path) const {
    ofstream f(path.c_str()); // создаём файл
    
    for (int i = 0; i < size; i++)
        f << (int) currencies[i]->GetType() << " " << currencies[i]->GetValue() << endl;
    
    f.close(); // закрываем в файл
}

// чтение из файла
void Purse::ReadFromFile(const string& path) {
    ifstream f(path.c_str()); // открываем файл
    
    int type;
    double value;
    
    while (f >> type >> value) {
        if (type == (int) CurrencyType::dollar) {
            AddCurrency(new Dollar(value)); // добавляем в долларах
        }
        else if (type == (int) CurrencyType::euro) {
            AddCurrency(new Euro(value)); // добавляем в евро
        }
        else if (type == (int) CurrencyType::pound) {
            AddCurrency(new Pound(value)); // добавляем в фунтах стерлингов
        }
    }
    
    f.close(); // закрываем файл
}

// вывод общей суммы в рублях
void Purse::PrintAmount() const {
    double amount = 0;
    
    for (int i = 0; i < size; i++) {
        amount += currencies[i]->ConvertToRub(); // переводим в рубли и прибавляем к общей сумме
        currencies[i]->Print(); // выводим каждую из валют
    }
    
    cout << "Amount in RUB: " << amount << endl << endl; // вывобим общую сумму
}

// вывод суммы по каждой валюте
void Purse::PrintByCurrency() const {
    double sum[3] = { 0, 0, 0 }; // массив для сумм по каждой из 3 валют
    
    for (int i = 0; i < size; i++) {
        CurrencyType type = currencies[i]->GetType(); // получаем тип валюты
        
        // в зависимости от типа валюты прибавляем к нужной сумме
        if (type == CurrencyType::dollar) {
            sum[0] += currencies[i]->ConvertToRub();
        }
        else if (type == CurrencyType::euro) {
            sum[1] += currencies[i]->ConvertToRub();
        }
        else if (type == CurrencyType::pound) {
            sum[2] += currencies[i]->ConvertToRub();
        }
    }
    
    // выводим повалютно значения в рублях
    cout << "Total in USD: " << sum[0] << endl;
    cout << "Total in EUR: " << sum[1] << endl;
    cout << "Total in GBP: " << sum[2] << endl;
}

// деструктор, освобождение памяти
Purse::~Purse() {
    for (int i = 0; i < size; i++)
        delete currencies[i]; // освобождаем память из-под объектов
    
    delete[] currencies; // освобождаем память от массива
}
