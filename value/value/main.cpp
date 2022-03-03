//
//  main.cpp
//  value
//
//  Created by Misha Esherkin on 08/04/2019.
//  Copyright © 2019 Misha Esherkin. All rights reserved.
//

/*
 Создать абстрактный класс Currency для работы с денежными суммами. Определить в нем методы перевода в рубли и вывода на экран.
 На его основе реализовать классы Dollar, Euro и Pound (фунт стерлингов) с возможностью пересчета в центы и пенсы соответственно.
 Создать класс Purse (кошелек), содержащий массив/параметризованную коллекцию объектов этих классов в динамической памяти.
 Предусмотреть возможность вывода общей суммы, переведенной в рубли, и суммы по каждой из валют. Написать демонстрационную программу,
 в которой будут использоваться все методы классов.
 
 Дополнительное задание: дополнить класс методами сортировки по некоторому критерию, вывода в файл и считывания из файла.
 */

#include <iostream>
#include <fstream>
#include <string>

#include "Currency.hpp"
#include "purse.hpp"

using namespace std;

int main() {
    Purse purse; // создаём кошелёк
    
    int n; // число валют для добавления
    cout << "Enter number of currencies: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int type; // тип валюты
        double value; // значение валюты
        
        cout << "Enter type (1 - dollar, 2 - euro, 3 - pounds): ";
        cin >> type; // считываем тип валюты
        
        cout << "Enter value: ";
        cin >> value; // считываем значение валюты
        
        if (type == 1) {
            purse.AddCurrency(new Dollar(value)); // добавляем в долларах
        }
        else if (type == 2) {
            purse.AddCurrency(new Euro(value)); // добавляем в евро
        }
        else if (type == 3) {
            purse.AddCurrency(new Pound(value)); // добавляем в фунтах стерлингов
        }
    }
    
    purse.PrintAmount(); // выводим общую сумму в рублях
    purse.PrintByCurrency(); // выводим суммы по отдельности
    
    purse.Sort();
    
    cout << endl << "After sort: " << endl;
    purse.PrintAmount(); // выводим общую сумму в рублях
    purse.PrintByCurrency(); // выводим суммы по отдельности
    
    purse.SaveToFile("out.txt"); // сохраняем в файл
    cout << "Saved to out.txt" << endl;
    
    purse.ReadFromFile("out.txt"); // добавляем из только что сохранёного файла
    
    cout << endl << "After adding from file:" << endl;
    purse.PrintAmount(); // выводим общую сумму в рублях
    purse.PrintByCurrency(); // выводим суммы по отдельности
}
