#include <iostream>
#include <fstream>
#include "compl.h"

using namespace std;

// получение комплексного числа из целого/вещественного или обычного числа
Complex GetArgument() {
    int type;
    cout << "Select type of argument (1 - real, 2 - integer, 3 - complex): ";
    cin >> type; // считываем тип числа
    
    if (type == 1) {
        double v;
        cout << "Enter real: ";
        cin >> v;
        
        return Complex(v); // возвращаем число из вещественного
    }
    
    if (type == 2) {
        int v;
        cout << "Enter integer: ";
        cin >> v;
        
        return Complex(v); // возвращаем число из целого
    }
    
    Complex c;
    cin >> c; // считываем комплексное число
    
    return c; // и возвращаем его
}

int main() {
    int item; // номер пункта меню
    ofstream f("result.txt");
    
    do {
        // выводим меню
        cout << "What do you want to do?" << endl;
        cout << "1. a + b" << endl;
        cout << "2. a - b" << endl;
        cout << "3. a * b" << endl;
        cout << "4. a / b" << endl;
        cout << "5. a++" << endl;
        cout << "6. a--" << endl;
        cout << "7. abs(a)" << endl;
        cout << "8. root(a)" << endl;
        cout << "9. Quit" << endl;
        cout << ">";
        cin >> item; // считываем номер пунтка меню
        
        // обрабатываем некорректный ввод
        while (item < 1 || item > 9) {
            cout << "Incorrect item. Try again: ";
            cin >> item;
        }
        
        // в зависимости от выбранного пункта выполняем действия
        if (item == 1) {
            Complex a = GetArgument();
            Complex b = GetArgument();
            Complex c = a + b;
            
            cout << "a + b = " << a << " + " << b << " = " << c << endl;
            f << "a + b = " << a << " + " << b << " = " << c << endl;
        }
        else if (item == 2) {
            Complex a = GetArgument();
            Complex b = GetArgument();
            Complex c = a - b;
            
            cout << "a - b = " << a << " - " << b << " = " << c << endl;
            f << "a - b = " << a << " - " << b << " = " << c << endl;
        }
        else if (item == 3) {
            Complex a = GetArgument();
            Complex b = GetArgument();
            Complex c = a * b;
            
            cout << "a * b = " << a << " * " << b << " = " << c << endl;
            f << "a * b = " << a << " * " << b << " = " << c << endl;
        }
        else if (item == 4) {
            Complex a = GetArgument();
            Complex b = GetArgument();
            Complex c = a / b;
            
            cout << "a / b = " << a << " / " << b << " = " << c << endl;
            f << "a / b = " << a << " / " << b << " = " << c << endl;
        }
        else if (item == 5) {
            Complex a = GetArgument();
            Complex b = a++;
            
            cout << "a++ = (" << a << ")++ = " << b << endl;
            f << "a++ = (" << a << ")++ = " << b << endl;
        }
        else if (item == 6) {
            Complex a = GetArgument();
            Complex b = a--;
            
            cout << "a-- = (" << a << ")-- = " << b << endl;
            f << "a-- = (" << a << ")-- = " << b << endl;
        }
        else if (item == 7) {
            Complex a = GetArgument();
            
            cout << "abs(a) = abs(" << a << ") = " << a.abs() << endl;
            f << "abs(a) = abs(" << a << ") = " << a.abs() << endl;
        }
        else if (item == 8) {
            Complex a = GetArgument();
            
            cout << "root(a) = root(" << a << "):" << endl;
            a.root(f);
        }
    } while (item != 9);
    
    f.close();
}
