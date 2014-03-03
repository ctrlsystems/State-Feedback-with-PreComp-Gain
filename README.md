State-Feedback-with-PreComp-Gain
================================
This entire project helps in understanding the concept of using Classes along with Control System Theory. The first project deals with a linearised system of a Nao Robot Arm. The dynamics is as follows

theta_double_dot = -b*theta/J   + K*T/J

where :

b, K, J - physical constants, involving inertia, mass 
T       - the input torque
theta   - the angle of the arm (considered to be the state)

An evolved system of equations in the following format xdot = A*x + B*u, is explained in "main.cpp". Further instructions of running the program, setting an object, mutating an object is explained in the file.

Dynamics.cpp & Dynamics.h are the files for generating the state and control of the system.
LinearAlgebra.cpp & LinearAlgebra.h define the only linear algebra function used in this system, a timeseries. 

Plotting the states and control can be done by using MATLAB and instructions are mentioned in the "main.cpp" file.
