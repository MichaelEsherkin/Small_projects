//
//  main.cpp
//  lab6
//
//  Created by Misha Esherkin on 29/11/2018.
//  Copyright © 2018 Misha Esherkin. All rights reserved.
//

#include "list.h"
#include <iostream>
#include <string>

using namespace std;

void addEl(LIST*, int);
void SearchEl(LIST*);
void DelEl(LIST*);

LIST *my_list;



int main()
{
    int dim = 0, menu, k = 0;
    char nf[15];
    string pr;
    bool check;
    
    cout << endl;
    
    do
    {
        cout << "************************" << endl;
        cout << "1. Ввод эл-ов списка" << endl;
        cout << "2. Просмотр списка" << endl;
        cout << "3. Поиск эл-ов в списке" << endl;
        cout << "4. Удалить эл-т из списка" << endl;
        cout << "5. Выход." << endl;
        cout << "************************" << endl;
        
        
        do
        {
            cout << "\nСделайте выбор: ?\b";
            cin >> menu;
            
            //if (isdigit(pr)) menu = (int)nf;
            //else cout << "Ошибка ввода!!" << endl;
            
            if (menu > 0 && menu < 6)
                break;
            else cin.clear(menu);
        } while (1);
        
        
        
        /////////////////////////////// {1
        switch (menu)
        {
            case 1:
                cout << "\nСколько элементов добавить в список: ?\b"; cin >> dim;
                addEl(my_list, dim);
                break;
            case 2:
                display(my_list);
                break;
            case 3:
                SearchEl(my_list);
                break;
            case 4:
                DelEl(my_list);
                break;
            case 5:
                exit(-1);
        }
        /////////////////////////////////// 1}
        
    } while (menu != 6);
    
    destroy_list(&my_list);
}

///////////////////////////////////////////////////////////////
//////////////////// Запись списка в файл /////////////////////
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
///////////////// Удаление элемента в списке //////////////////
///////////////////////////////////////////////////////////////

void DelEl(LIST *lst)
{
    int k = 0, sp;
    LIST *DelList = new LIST;
    DelList = lst;
    LIST *items = new LIST;
    
    cout << "\n\n***********************" << endl;
    display(DelList);
    cout << "\n Какой элемент удалить из списка: ?\b"; cin >> sp;
    
    while (DelList != NULL)
    {
        cout << "1" << endl;
        if (k == sp - 1)
        {
            items = DelList;
            take_out(&my_list, items);
            break;
        }
        k++;
        DelList = DelList->next;
    }
    display(my_list);
}

///////////////////////////////////////////////////////////////
/////////////////// Поиск элемента в списке ///////////////////
///////////////////////////////////////////////////////////////

void SearchEl(LIST *lst)
{
    int menu;
    char nf[15];
    bool check = false;
    
    LIST *Search = lst;
    
    cout << "\n\n*****Поиск эл-ов списка*****" << endl;
    cout << "1. По имени" << endl;
    cout << "2. По фамилии" << endl;
    cout << "3. По типу" << endl;
    cout << "4. Выход" << endl;
    cout << "****************************" << endl;
    
    do
    {
        cout << "Сделайте выбор: ?\b"; cin >> menu;
        if (menu > 0 && menu < 5) check = false;
    } while (check);
    cout << "\n\n****************************" << endl;
    
    switch (menu)
    {
        case 1:
            
            cout << "\nВведите имя: "; cin >> nf;
            while (Search != NULL)
            {
                if (strcmp(Search->first_name, nf) == 0)
                {
                    cout << "\n" << Search->last_name << " " << Search->first_name << endl;
                    cout << "Возраст: " << Search->age;
                    
                    switch (Search->tag)
                    {
                        case student:
                            cout << "Специализация: " << Search->node_tag.student.grade_pt_avarage << endl;
                            cout << "Курс: " << Search->node_tag.student.grade_pt_avarage << endl;
                            break;
                        case professor:
                            cout << "Номер кафедры: " << Search->node_tag.professor.dept_number << endl;
                            cout << "Оклад: " << Search->node_tag.professor.annual_salary << endl;
                            break;
                        case staff:
                            cout << "Срок службы: " << Search->node_tag.staff.years_of_service << endl;
                            cout << "Почасовой тариф: " << Search->node_tag.staff.hourly_wage << endl;
                    }
                }
                Search = Search->next;
            }
            break;
            
        case 2:
            
            cout << "Введите фамилию: "; cin >> nf;
            while (Search != NULL)
            {
                if (strcmp(Search->last_name, nf) == 0)
                {
                    cout << "\n\n" << Search->last_name << " " << Search->first_name << endl;
                    cout << "Возраст: " << Search->age << endl;
                    
                    switch (Search->tag)
                    {
                        case student:
                            cout << "Средний балл: " << Search->node_tag.student.grade_pt_avarage << endl;
                            cout << "Курс: " << Search->node_tag.student.level << endl;
                            break;
                        case professor:
                            cout << "Номер кафедры: " << Search->node_tag.professor.dept_number << endl;
                            cout << "Оклад: " << Search->node_tag.professor.annual_salary << endl;
                            break;
                        case staff:
                            cout << "Срок службы: " << Search->node_tag.staff.years_of_service << endl;
                            cout << "Почасовой тариф: " << Search->node_tag.staff.hourly_wage << endl;
                    }
                }
                Search = Search->next;
            }
            break;
            
        case 3:
            
            cout << "\n****************************" << endl;
            cout << "1. Персонал" << endl;
            cout << "2. Студенты" << endl;
            cout << "3. Профессора" << endl;
            cout << "****************************" << endl;
            
            do
            {
                cout << "Сделайте выбор: ?\b"; cin >> menu;
                if (menu > 0 && menu < 4) check = false;
            } while (check);
            cout << "\n\n****************************";
            
            switch (menu)
        {
            case 1:
                
                while (Search != NULL)
                {
                    if (Search->tag == staff)
                    {
                        cout << "\n\n" << Search->last_name << " " << Search->first_name << endl;
                        cout << "Возраст: " << Search->age << endl;
                        cout << "Срок службы: " << Search->node_tag.staff.years_of_service << endl;
                        cout << "Почасовой тариф: " << Search->node_tag.staff.hourly_wage << endl;
                    }
                    Search = Search->next;
                }
                
                break;
            case 2:
                
                while (Search != NULL)
                {
                    if (Search->tag == student)
                    {
                        cout << "\n\n" << Search->last_name << " " << Search->first_name << endl;
                        cout << "Возраст: " << Search->age << endl;
                        cout << "Средний балл: " << Search->node_tag.student.grade_pt_avarage << endl;
                        cout << "Курс: " << Search->node_tag.student.level << endl;
                    }
                    Search = Search->next;
                }
                
                break;
            case 3:
                
                while (Search != NULL)
                {
                    if (Search->tag == professor)
                    {
                        cout << "\n\n" << Search->last_name << " " << Search->first_name << endl;
                        cout << "Возраст: " << Search->age << endl;
                        cout << "Номер кафедры: " << Search->node_tag.professor.dept_number << endl;
                        cout << "Оклад: " << Search->node_tag.professor.annual_salary << endl;
                    }
                    Search = Search->next;
                }
                
                break;
        }
            /////////////////////////////////// 2}
            destroy_list(&Search);
            break;
    }
    cout << "\n*****Нажмите Enter, для продолжения*****" << endl;
    getchar();
}

///////////////////////////////////////////////////////////////
///////////////// Добавить элемент в списке ///////////////////
///////////////////////////////////////////////////////////////

void addEl(LIST *lst, int dim = 1)
{
    int sp;
    char nf[15];
    bool check = true;
    
    LIST *items = new LIST;
    
    for (int i = 0; i < dim; i++)
    {
        do
        {
            cout << "\nВведите имя: "; cin >> nf;
            strcpy(items->first_name, nf);
            if (is_present(my_list, items))
            {
                cout << "\nВведите фамилию: "; cin >> nf;
                strcpy(items->last_name, nf);
                if (is_present(my_list, items))
                {
                    cout << "\nПользователь с таким именем и фамилией уже имеется," << endl;
                    cout << "ввести фамилию заново(1), или продолжить ввод данных(2): ?\b"; cin >> sp;
                    if (sp != 1) check = false;
                }
                else check = false;
            }
            else
            {
                cout << "\nВведите фамилию: "; cin >> nf;
                strcpy(items->last_name, nf);
                check = false;
            }
        } while (check);
        
        cout << "\nВведите возраст: "; cin >> items->age;
        cout << "\nВведите должность(1.staff, 2.student, 3.professor): "; cin >> sp;
        if (sp == 1)
        {
            items->tag = staff;
            cout << "\nВведите срок службы: "; cin >> items->node_tag.staff.years_of_service;
            cout << "\nВведите почасовой тариф($): "; cin >> items->node_tag.staff.hourly_wage;
        }
        else if (sp == 2)
        {
            items->tag = student;
            cout << "\nВведите курс: "; cin >> items->node_tag.student.level;
            cout << "\nВведите средний балл: "; cin >> items->node_tag.student.grade_pt_avarage;
        }
        else if (sp == 3)
        {
            items->tag = professor;
            cout << "\nВведите номер кафедры: "; cin >> items->node_tag.professor.dept_number;
            cout << "\nВведите годовой оклад: "; cin >> items->node_tag.professor.annual_salary;
        }
        else
        {
            cout << "Неверно введен номер.." << endl;
            getchar();
            exit(-1);
        }
        insert(&my_list, items);
    }
}

/////////////////////////////////////////////////////

static LIST *create_node(LIST *item)
{
    LIST *node;
    node = (LIST *)malloc(sizeof(LIST));
    *node = *item;
    return node;
}

void destroy_list(LIST **lst)
{
    LIST *current_node = *lst;
    LIST *previous_node = 0;
    while (current_node != 0)
    {
        previous_node = current_node;
        current_node = current_node->next;
        free(previous_node);
    }
    *lst = 0;
}

void take_out(LIST **lst, LIST *item)
{
    LIST *current_node = *lst;
    LIST *previous_node = 0;
    while (current_node != 0 && strcmp(current_node->last_name, item->last_name) != 0)
    {
        insert(&previous_node, current_node);
        current_node = current_node->next;
    }
    if (current_node == 0 && previous_node != 0)
    {
        //do
        //{
        //    current_node = current_node->next;
        //    insert(&previous_node, current_node);
        //} while (current_node != NULL);
        *lst = current_node->next;
        free(current_node);
    }
    else if (current_node->next != 0)
    {
        do
        {
            current_node = current_node->next;
            insert(&previous_node, current_node);
        } while (current_node->next != NULL);
        free(current_node);
    }
    *lst = previous_node;
}

void insert(LIST **lst, LIST *item)
{
    char key[10];
    LIST *current_node = *lst;
    LIST *previous_node = 0;
    LIST *new_node = 0;
    strcpy(key, item->last_name);
    while (current_node != 0 && strcmp(item->last_name, key) < 0)
    {
        previous_node = current_node;
        current_node = current_node->next;
    }
    new_node = create_node(item);
    new_node->next = current_node;
    if (previous_node == 0)
        *lst = new_node;
    else
        previous_node->next = new_node;
}

void display(LIST *lst)
{
    int i = 1;
    LIST *current = lst;
    while (current != NULL)
    {
        cout << "\n№ " << i++ << ": " << current->last_name << " " << current->first_name;
        cout << "\nВозраст = " << current->age << endl;
        
        switch (current->tag)
        {
            case student:
                cout << "Специализация: " << current->node_tag.student.grade_pt_avarage << endl;
                cout << "Курс: " << current->node_tag.student.grade_pt_avarage << endl;
                break;
            case professor:
                cout << "Номер кафедры: " << current->node_tag.professor.dept_number << endl;
                cout << "Оклад: " << current->node_tag.professor.annual_salary << endl;
                break;
            case staff:
                cout << "Срок службы: " << current->node_tag.staff.years_of_service << endl;
                cout << "Почасовой тариф: " << current->node_tag.staff.hourly_wage << endl;
        }
        current = current->next;
    }
    cout << "\n\n***Нажмите Enter, что бы продолжить..***" << endl;
    getchar();
}

int is_present(LIST *lst, LIST *item)
{
    LIST *current_node = lst;
    while (current_node && strcmp(item->last_name, current_node->last_name) != 0)
        if (strcmp(item->last_name, current_node->last_name) != 0)
            current_node = current_node->next;
    return(current_node != 0);
}



