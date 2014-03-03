//
//  main.cpp
//  Nao
//
//  Created by Saraswathi Nambi on 2/23/14.
//  Copyright (c) 2014 __ctrlsystems__. All rights reserved.
//


    /*  The following program demonstrates how to run a State Feedback Control. The physical system in demonstration is a linearized version of the arm of a Nao Robot. We assume that the states of the system are fully known and design a State Feedback Controller for the same

                   --------          -------          ------
               (+)|        |  u(t)  |       |   x(t) |      |     y(t)
      ----r(t)--->|    B   |------->|   A   |------->|  C   |------->
            |     |        |        |       |   |    |      |
         (-)|      --------          -------    |     ------
            |                                   |
            |                 K                 |
            ----------------<<<------------------

        xdot = A*x + B*u
        y    = C*x

           A = [0   1;
                0 -b/J];

           B = [0; 
               -K/J];

           C = [1 0];

      where x1 is the position of the arm and x2 is the velocity of the arm. A step input is given to the system for tracking control.

      The system is completely controllable (i.e Rank of Controlability Matrix is of Full Rank) and is also completely observable (i.e Rank of Observability Matrix is of Full Rank).

        NOTE: The algorithms for Stability, Controllability and Observability will be discussed in coming projects. Algorithms which include pole placement, eigenvalues will be discussed in future projects. This project showcases only "the use of classes for designing a State Feedback controller". The eigenvalues for the characteristic equation of (A - B*K) were placed at (-15 + 5i) & (-15 - 5i). On a comparison, I obtained the two values for the gain matrix, Ki = [-250; -30]. For now, we can take k1 = -250 and k2 = -30 and the precompensation gain for the reference signal kr = k1.

            //TO PONDER: What are the advantages and disadvantages of choosing such large gains???????

        BUILDING & COMPILING THE FILES:

        Since we have more than one file to run, follow the instructions:
        1. Copy all files to one folder location
        2. Open terminal, navigate to the folder location
        3. Open terminal  $g++ main.cpp Dynamics.cpp LinearAlgebra.cpp -o main (works only if you have g++/clang compiler in your system)
        4. This will create the executable "main", now type ./main and hit return
        5. Now the data file containing all vectors of state and control will be produced.

        NOTE: If you tend to use an IDE like XCODE, Visual Studio, building and compiling the project will be much easier. In future projects, compiling using make files will be included
 */

#include <iostream>
#include <cmath>
#include <vector>
#include "Dynamics.h"

using namespace std;
int main()
{
    //NOTE: It would be a good practice to declare all constants before creating an object. I have declared in sections to have a flow of where we use them.

    //Creating an object
    Dynamics nao;
        
    //We need to set the physical constant values and the initial conditions for integration of the dynamics
    double b = 10.0; double K = 100.0; double J = 100.0;
    double x1 = 0.0; double x2 = 0.0; double u = 0.0;
    nao.set_constants(b, K, J);
    nao.set_init(x1, x2, u);

    //Integrating the dynamics to generate control and thereby the states of the system
    double k1 = -250.0; double k2 = -30.0;
    nao.set_state(k1, k2, k1);
    
    //Creating a .dat file for use of plotting the position and velocity of the vector.
    nao.create_file();
       
    return 0;
}

/*    PLOT USING MATLAB:
    When you copy the 'states.dat' to MATLAB directory, you need to import data to the Workspace. Once it is done you can copy+paste the following snippet of code to        view the position of the arm
    plot(data(:,2), 'b');
    plot(data(:,1), 'r-.');
    grid on;
    hold on;
    title('Step Input Response for Nao Robot');
    xlabel('Time'); 
    ylabel('Position of the arm');
 */


