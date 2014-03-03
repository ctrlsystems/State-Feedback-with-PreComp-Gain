//
//  LinAlg.cpp
//  Nao
//
//   Created by Saraswathi Nambi on 2/25/14.
//  Copyright (c) 2014 __ctrlsystems__. All rights reserved.


#include "LinearAlgebra.h"

LinearAlgebra::LinearAlgebra()
{
     n1 = 0.0; n2 = 10.0; step = 0.1;
}

LinearAlgebra::~LinearAlgebra(){ }

/*--------------------------------LINSPACE--------------------------------*/

void LinearAlgebra::set_linspace(double new_n1, double new_n2, double new_step)
{
    n1 = new_n1; n2 = new_n2; step = new_step;
    
    //The size of the vector
    N =  (int16_t)(((n2 - n1)/step) + 1);
    
    //The linear time series is created
    while (n1 <= n2)
    {
        ls.push_back(n1);
        n1 += step;
    }
    
}
/*-------------------Accessing SIZE and RANGE of LINSPACE---------------*/
int LinearAlgebra::get_size_vector() const
{
    return N;
}

vector<double> LinearAlgebra::get_linspace() const
{
    return ls;
}
/*------------------------------END OF LINSPACE-------------------------*/



