//
//  Header.h
//  lab6
//
//  Created by Misha Esherkin on 29/11/2018.
//  Copyright © 2018 Misha Esherkin. All rights reserved.
//

#ifndef list_h
#define list_h

#pragma once


#define STAFF struct stuff_type

STAFF
{
    int years_of_service;
    double hourly_wage;
};

#define STUDENT struct student_type

STUDENT
{
    double grade_pt_avarage;
    int level;
};

#define PROFESSOR struct prof_type

PROFESSOR
{
    int dept_number;
    double annual_salary;
};

#define NODE_TYPE enum node_type

typedef NODE_TYPE{ student, professor, staff };

#define LIST struct list

LIST
{
    char last_name[10];
    char first_name[10];
    int age;
    LIST *next;
    NODE_TYPE tag;
    union
    {
        STUDENT student;
        PROFESSOR professor;
        STAFF staff;
    } node_tag;
};

extern void insert(LIST **lst, LIST *item);
extern void display(LIST *lst);
extern int is_present(LIST *lst, LIST *item);
extern void take_out(LIST **lst, LIST *item);
extern void destroy_list(LIST **lst);

#endif /* Header_h */
