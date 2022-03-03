//
//  complex.h
//  lab5
//
//  Created by Misha Esherkin on 28/11/2018.
//  Copyright © 2018 Misha Esherkin. All rights reserved.
//

struct complex
{
    double real;
    double image;
    double result;
};
complex operator+(complex &, complex &);
complex operator+(complex &z1, complex &z2)
{
    complex result;
    result.real = z1.real + z2.real;
    result.image = z1.image + z2.image;
    return result;
};
complex operator-(complex &, complex &);
complex operator-(complex &z1, complex &z2)
{
    complex result;
    result.real = z1.real - z2.real;
    result.image = z1.image - z2.image;
    return result;
};
complex operator*(complex &, complex &);
complex operator*(complex &z1, complex &z2)
{
    complex result;
    result.real = z1.real * z2.real - z1.image * z2.image;
    result.image = z1.real * z2.image + z1.image * z2.real;
    return result;
};
complex operator/(complex &, complex &);
complex operator/(complex &z1, complex &z2)
{
    complex result;
    float x = z2.real * z2.real + z2.image * z2.image;
    result.real =  (z1.real * z2.real + z1.image * z2.image) / x;
    result.image = (z2.real * z1.image - z1.real * z2.image) / x;
    return result;
};

#ifndef complex_h
#define complex_h


#endif /* complex_h */
