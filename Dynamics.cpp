//
//  Dynamics.cpp
//  Nao
//
//  Created by Saraswathi Nambi on 2/25/14.
//  Copyright (c) 2014 __ctrlsystems__. All rights reserved.
//

#include "Dynamics.h"
#include "LinearAlgebra.h"

using namespace std;

//DEFAULT CONSTRUCTOR
Dynamics::Dynamics() 
{
   
    b  = 10.0; K = 100.0; J = 100.0;
    x1 = 0.0; x2 = 0.0;   u  = 0.0;
}

//DEFAULT DESTRUCTOR
Dynamics::~Dynamics(){}

/*---------------------------DYNAMICS OF NAO-------------------------- */

/*------------------Set CONSTANTS for the Dynamics of Nao------------- */
void Dynamics::set_constants(double new_b, double new_K, double new_J)
{
    b = new_b; K = new_K; J = new_J;
}

/*-----------------------Set Initial Conditions----------------------- */
void Dynamics::set_init(double new_x1, double new_x2, double new_u)
{
    x1 = new_x1; x2 = new_x2; u = new_u;
}

/*-----------------------State Space Equations----------------------- */
void Dynamics::set_state(double k1, double k2, double kr)
{
    double dx1, dx2, r;
    
    //    Generating a linear time series
    double n1 = 0.0;
    double n2 = 10.0;
    double step = 0.01;
    LinearAlgebra time;
    time.set_linspace(n1,n2,step);
    int  N = time.get_size_vector();
    vector<double> timeSeries = time.get_linspace();
    
    
    for (int i = 0; i < N; i++)
    {
    //    Creating a step input as the reference signal 'r' depending on the time space.
        if((timeSeries[i] > n1) && (timeSeries[i] <= n2/2))
        {
            r = 0.0;
        }
        else if ((timeSeries[i] > n2/2) && (timeSeries[i] <= n2))
        {
            r = 1.0;
        }
        
    //    The control input u = -K*(x -r)
        u = - (k1 * x1) - (k2 * x2) + (kr * r);
        
    //    The state dynamics of the system, xdot = A*x + B*u
        dx1 = x2;
        dx2 = -(K * u)/J - (b * x2)/J;
        
    //    The system is integrated using Euler method of integration
        x1 = x1 + dx1 * step;
        x2 = x2 + dx2 * step;
        
    //    The states are stored in as individual vectors
        X1.push_back(x1);
        X2.push_back(x2);
        U.push_back(u);
        R.push_back(r);
        
    }
}
/*---------------------------END OF NAO DYNAMICS-------------------------- */

/*------------------------------DATA OUTPUT----------------------------- */
void Dynamics::create_file()
{
    ofstream data("states.dat");
    if (!data)
    {
        cerr << "the file cannot be created!" << endl;  
        exit(1);
        
    }
    else 
    {
        data << "referenceSignal(rad)" << " " << "position(rad)" << " " << "velocity(rad/s)" << " " << "control(rad/s)" << endl;
        
        for (int i = 0; i < X1.size(); i++)
        {
            data << R[i] << " " << X1[i] << " " << X2[i] << " " << U[i] << endl;
        }
        data.close();
        cout << "The State Feedback Control example has finished its run! The output is stored in 'states.dat' file" << endl;
    }
}
/*------------------------END OF DATA OUTPUT----------------------------- */
