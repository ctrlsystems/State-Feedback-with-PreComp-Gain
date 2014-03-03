//
//  Dynamics.h
//  Nao
//
//  Created by Saraswathi Nambi on 2/25/14.
//  Copyright (c) 2014 __ctrlsystems__. All rights reserved.
//
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

#ifndef Nao_Dynamics_h
#define Nao_Dynamics_h

class Dynamics
{
public:
    /*----Default Constructor and Destructor-----*/
    Dynamics();
    ~Dynamics();
    
    
    /*--------Mutator Members--------*/
    
    void set_constants(double, double, double);
    void set_init(double, double, double);
    
    /*--------Dynamics of Nao, Control Design --------*/
    void set_state(double, double, double);
   
    /*------ Writing Data to a File ------*/
    void create_file();
    
private:
    double b, K, J;
    double x1, x2, u;
    
    
    vector <double> X1;
    vector <double> X2;
    vector <double> U;
    vector <double> R;
};

#endif
