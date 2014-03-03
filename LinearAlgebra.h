//
//  LinAlg.h
//  Nao
//
//  Created by Saraswathi Nambi on 2/25/14.
//  Copyright (c) 2014 __ctrlsystems__. All rights reserved.


#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

#ifndef Nao_LinearAlgebra_h
#define Nao_LinearAlgebra_h

class LinearAlgebra
{
    
public:
    LinearAlgebra();
    ~LinearAlgebra();
    
    /*--------Mutator Members--------*/
void set_linspace(double, double, double);

    /*--------Accessing Linear Space--------*/
vector<double> get_linspace() const;
int get_size_vector() const;

private:
    
    double n1, n2, step;
    vector<double> ls;
    int N;
    
};

#endif
