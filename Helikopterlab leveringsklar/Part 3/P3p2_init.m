% FOR HELICOPTER NR 3-10
% This file contains the initialization for the helicopter assignment in
% the course TTK4115. Run this file before you execute QuaRC_ -> Build 
% to build the file heli_q8.mdl.

% Oppdatert h?sten 2006 av Jostein Bakkeheim
% Oppdatert h?sten 2008 av Arnfinn Aas Eielsen
% Oppdatert h?sten 2009 av Jonathan Ronen
% Updated fall 2010, Dominik Breu
% Updated fall 2013, Mark Haring
% Updated spring 2015, Mark Haring


%%%%%%%%%%% Calibration of the encoder and the hardware for the specific
%%%%%%%%%%% helicopter
Joystick_gain_x = 1;
Joystick_gain_y = -1;


%%%%%%%%%%% Physical constants
g = 9.81; % gravitational constant [m/s^2]
l_c = 0.46; % distance elevation axis to counterweight [m]
l_h = 0.66; % distance elevation axis to helicopter head [m]
l_p = 0.175; % distance pitch axis to motor [m]
m_c = 1.92; % Counterweight mass [kg]
m_p = 0.72; % Motor mass [kg]


% CONSTANTS - Part III
v_star = 6.8;
k_f = -((m_c*g*l_c-2*m_p*g*l_h)/(v_star*l_h));  
l_1 = l_p*k_f;
l_3 = l_h*k_f;
j_p = 2*m_p*l_p*l_p;
j_e = m_c*l_c*l_c+2*m_p*l_h*l_h;
k_1 = l_1/j_p;
k_2 = l_3/j_e; 

% CONTROLLABILITY MATRIX - Part III
C_cont = [B A*B A*A*B];  

% MATRICES - Part III, problem 2
A = [0 1 0; 0 0 0; 0 0 0];
B = [0 0;0 k_1;k_2 0]; 
C = [1 0 0; 0 0 1];

q_1 = 95;       
q_2 = 10;       
q_3 = 110;      
v=[q_1,q_2,q_3];
Q = diag(v);
R = [1 0 ; 0 1 ];

K = lqr(A, B, Q, R);
P = inv(C*(inv(B*K - A))*B);

