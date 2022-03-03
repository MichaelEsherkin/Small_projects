#include <iostream>
#include <cmath>
#include <fstream>
#include "complex.h"
using namespace std;
void Plus();
void UnarPlus();
void Minus();
void UnarMinus();
void Multiplier();
void Division();
void Abs();
void Conj();
void Sqr();

int main()
{
    int choice;
    for (;;)
    {
        do
        {
            
            cout << "\n Операции: \n 1.Сложение \n 2.Унарный плюс \n 3.Вычитания \n 4.Унарный минус \n 5.Умножение \n 6.Деление \n 7.Модуль \n 8.Комплексное сопряжение \n 9.Квадратный корень \n 10. Выход" <<endl;
            cout << "Выберите операцию" << endl;
            cin >> choice;
            if(choice > 0 && choice < 11)
                break;
        }
        while(1);
        
        switch (choice)
        {
            case 1:
                Plus();
                break;
            case 2:
                UnarPlus();
                break;
            case 3:
                Minus();
                break;
            case 4:
                UnarMinus();
                break;
            case 5:
                Multiplier();
                break;
            case 6:
                Division();
                break;
            case 7:
                Abs();
                break;
            case 8:
                Conj();
                break;
            case 9:
                Sqr();
                break;
            case 10:
                exit(-1);
                break;
        }
    }
}
void Plus()
{
    cout << "Операция: сложение" << endl;
    complex z1;
    cout << "Введите действительную часть первого числа" << endl;
    cin >> z1.real;
    cout << "Введите мнимую часть первого числа" << endl;
    cin >> z1.image;
    complex z2;
    cout << "Введите действительную часть второго числа" << endl;
    cin >> z2.real;
    cout << "Введите мнимую часть второго числа" << endl;
    cin >> z2.image;
    complex z3;
    cout << z1.real << "+" << z1.image << "i" << "+";
    getchar();
    cout << z2.real << "+" << z2.image << "i" << "=";
    getchar();
    z3 = z1 + z2;
    cout << z3.real << "+" << z3.image << "i";
    getchar();
    ofstream ofs ("Result.txt", ios_base::app);
    ofs << endl << z1.real << "+" << z1.image << "i" << "+" << z2.real << "+" << z2.image << "i" << "=" << z3.real << "+" << z3.image << "i";
    ofs.close();
}
void Minus()
{
    cout << "Операция: вычетание" << endl;
    complex z1;
    cout << "Введите действительную часть первого числа" << endl;
    cin >> z1.real;
    cout << "Введите мнимую часть первого числа" << endl;
    cin >> z1.image;
    complex z2;
    cout << "Введите действительную часть второго числа" << endl;
    cin >> z2.real;
    cout << "Введите мнимую часть второго числа" << endl;
    cin >> z2.image;
    complex z3;
    cout << z1.real << "+" << z1.image << "i" << "-";
    getchar();
    cout << z2.real << "+" << z2.image << "i" << "=";
    getchar();
    z3 = z1 - z2;
    cout << z3.real << "" << z3.image << "i";
    getchar();
    ofstream ofs ("Result.txt", ios_base::app);
    ofs << endl << z1.real << "+" << z1.image << "i" << "-" << z2.real << "+" << z2.image << "i" << "=" << z3.real << "+" << z3.image << "i";
    ofs.close();
}
void Multiplier()
{
    cout << "Операция: умножение" << endl;
    complex z1;
    cout << "Введите действительную часть первого числа" << endl;
    cin >> z1.real;
    cout << "Введите мнимую часть первого числа" << endl;
    cin >> z1.image;
    complex z2;
    cout << "Введите действительную часть второго числа" << endl;
    cin >> z2.real;
    cout << "Введите мнимую часть второго числа" << endl;
    cin >> z2.image;
    complex z3;
    cout << z1.real << "+" << z1.image << "i" << "*";
    getchar();
    cout << z2.real << "+" << z2.image << "i" << "=";
    getchar();
    z3 = z1 * z2;
    cout << z3.real << "+" << z3.image << "i";
    getchar();
    ofstream ofs ("Result.txt", ios_base::app);
    ofs << endl << z1.real << "+" << z1.image << "i" << "*" << z2.real << "+" << z2.image << "i" << "=" << z3.real << "+" << z3.image << "i";
    ofs.close();
}

void Division()
{
    cout << "Операция: деление" << endl;
    complex z1;
    cout << "Введите действительную часть первого числа" << endl;
    cin >> z1.real;
    cout << "Введите мнимую часть первого числа" << endl;
    cin >> z1.image;
    complex z2;
    cout << "Введите действительную часть второго числа" << endl;
    cin >> z2.real;
    cout << "Введите мнимую часть второго числа" << endl;
    cin >> z2.image;
    complex z3;
    cout << z1.real << "+" << z1.image << "i" << "/";
    getchar();
    cout << z2.real << "+" << z2.image << "i" << "=";
    getchar();
    z3 = z1 / z2;
    cout << z3.real << "+" << z3.image << "i";
    getchar();
    ofstream ofs ("Result.txt", ios_base::app);
    ofs << endl << z1.real << "+" << z1.image << "i" << "/" << z2.real << "+" << z2.image << "i" << "=" << z3.real << "+" << z3.image << "i";
    ofs.close();
}

void UnarPlus()
{
    cout << "Операция: унарный плюс" << endl;
    complex z1;
    cout << "Введите действительную часть числа" << endl;
    cin >> z1.real;
    cout << "Введите мнимую часть числа" << endl;
    cin >> z1.image;
    cout << z1.real << "+" << z1.image << "i";
    getchar();
    ofstream ofs ("Result.txt", ios_base::app);
    ofs << endl << z1.real << "+" << z1.image << "i";
    ofs.close();
}
void UnarMinus()
{
    cout << "Операция: унарный минус" << endl;
    complex z1;
    cout << "Введите действительную часть числа" << endl;
    cin >> z1.real;
    z1.real = - z1.real;
    cout << "Введите мнимую часть числа" << endl;
    cin >> z1.image;
    z1.image = - z1.image;
    cout << z1.real << "+" << z1.image << "i";
    getchar();
    ofstream ofs ("Result.txt", ios_base::app);
    ofs << endl << z1.real << "+" << z1.image << "i";
    ofs.close();
}
void Abs()
{
    complex z1;
    cout << "Операция: Модуль комплексного числа" << endl;
    cout << "Введите действительную часть числа" << endl;
    cin >> z1.real;
    cout << "Введите мнимую часть числа" << endl;
    cin >> z1.image;
    complex z3;
    cout << "|" << z1.real << "+" << z1.image << "i" << "|" << " = ";
    z3.real = pow(z1.real, 2.0) + pow(z1.image, 2.0);
    cout << "Модуль" << z3.real << " = ";
    z3.image = sqrt(z3.real);
    cout << z3.image;
    getchar();
    ofstream ofs ("Result.txt", ios_base::app);
    ofs << endl << "|" << z1.real << "+" << z1.image << "i" << "|" << " = " << "Модуль" << z3.real << " = " << z3.image;
    ofs.close();
}
void Conj()
{
    cout << "Операция: Комплексное сопряжение" << endl;
    complex z1;
    cout << "Введите действительную часть числа" << endl;
    cin >> z1.real;
    z1.real = z1.real;
    cout << "Введите мнимую часть числа" << endl;
    cin >> z1.image;
    z1.image = - z1.image;
    cout << z1.real << "+" << z1.image << "i";
    getchar();
    ofstream ofs ("Result.txt", ios_base::app);
    ofs << endl << z1.real << "+" << z1.image << "i";
    ofs.close();
}
void Sqr()
{
    complex z1;
    cout << "Операция: Квадратный корень из комплексного числа" << endl;
    cout << "Введите действительную часть  числа" << endl;
    cin >> z1.real;
    cout << "Введите мнимую часть числа" << endl;
    cin >> z1.image;
    complex z3;
    complex z4;
    if ( z1.image != 0 )
    {
        z3.image = sqrt ( (- z1.real + sqrt ( pow(z1.real, 2.0) +  pow(z1.image, 2.0) ) ) / 2 );
        z4.image = ( - 1 ) * sqrt ( (- z1.real + sqrt ( pow(z1.real, 2.0) +  pow(z1.image, 2.0) ) ) / 2);
        z3.real =  z1.image /  ( 2 * z3.image );
        z4.real =  z1.image /  ( 2 * z4.image );
    }      else if ( z1.real < 0 )
    {
        z3.image = sqrt ( (- z1.real + sqrt ( pow(z1.real, 2.0) +  pow(z1.image, 2.0) ) ) / 2 );
        z4.image = ( - 1 ) * sqrt ( (- z1.real + sqrt ( pow(z1.real, 2.0) +  pow(z1.image, 2.0) ) ) / 2);
        z3.real =  z1.image /  ( 2 * z3.image );
        z4.real =  z1.image /  ( 2 * z4.image );
    }       else
    {
        z3.image = 0 ;
        z4.image = 0 ;
        z3.real = sqrt ( z1.real ) ;
        z4.real = ( - 1 ) * sqrt ( z1.real ) ;
    }
    
            cout << "Квадратный корень_1 = " << z3.real << "+" << z3.image << "i" << endl;
            cout << "Квадратный корень_2 = " << z4.real << "+" << z4.image << "i";
            getchar();
            ofstream ofs ("Result.txt", ios_base::app);
            ofs << endl << "Квадратный корень_1 =" << z3.real << "+" << z3.image << "i";
            ofs << endl << "Квадратный корень_2 =" << z4.real << "+" << z4.image << "i";
            ofs.close();
}
