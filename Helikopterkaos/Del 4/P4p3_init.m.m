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
v_star = 6.8;
k_f = -((m_c*g*l_c-2*m_p*g*l_h)/(v_star*l_h)); % motor force constant
l_1 = l_p*k_f;
l_2 = g*((l_c*m_c) - (l_h*m_p));
l_3 = l_h*k_f;
l_4 = l_h*k_f;
j_p = 2*m_p*l_p*l_p;
j_e = m_c*l_c*l_c+2*m_p*l_h*l_h;
j_lambda = m_c*l_c*l_c+2*m_p*(l_h*l_h + l_p*l_p);
k_1 = l_1/j_p;
k_2 = l_3/j_e; 
k_3 = -(l_4*l_2)/(j_lambda * l_3);

%C_cont = [B A*B A*A*B];  % controllability


q_1 = 1;   % p
q_2 = 0.1;   % p_dot
q_3 = 110;  % e_dot
q_4 = 5;    % gamma (pitch dff)
q_5 = 50;    % zeta (elev diff)

old_v = [q_1, q_2, q_3];

old_A = [0 1 0 ; 0 0 0 ; 0 0 0];
old_B = [0 0; 0 k_1; k_2 0]; 
old_C = [1 0 0 ; 0 0 1 ];
old_Q = diag(old_v);
R = [1 0 ; 0 1 ];

old_K = lqr(old_A, old_B, old_Q, R);
%P = inv(old_C*(inv(old_B*old_K - old_A))*old_B);

% A-BK
A=[0 1 0 0 0 ; 0 0 0 0 0; 0 0 0 0 0; 1 0 0 0 0; 0 0 1 0 0];
C=[1 0 0 0 0; 0 0 1 0 0];
B=[0 0; 0 k_1; k_2 0;0 0; 0 0];

v = [q_1, q_2, q_3,q_4,q_5];
Q=diag(v);

K=lqr(A,B,Q,R);
%D = [0 0; 0 0; 0 0; -1 0; 0 -1];
P = [0  K(2,1); K(1,3) 0];

% A-LC - observer
A_est=[0 1 0 0 0 0; 0 0 0 0 0 0; 0 0 0 1 0 0; 0 0 0 0 0 0; 0 0 0 0 0 1; k_3 0 0 0 0 0];
C_est=[0 0 1 0 0 0; 0 0 0 0 1 0];
B_est=[0 0; 0 k_1; 0 0; k_2 0;0 0; 0 0];

factor = 5;                                 % skaleringsfaktor fra største pol i (A-BK)
r = factor * max(abs(eig(A-B*K)));          % radius for polplassering
theta = (5/6)* pi;                          % vinkel for polplassering
theta2 = theta + pi/3;                      % motsatt vinkel for polplassering
n = 6;                                      % antall poler
list_of_pole_angles = linspace(theta, theta2, n);
poles = cplxpair(([r*exp(1j*list_of_pole_angles(1)) r*exp(1j*list_of_pole_angles(6)) r*exp(1j*list_of_pole_angles(3)) r*exp(1j*list_of_pole_angles(4)) r*exp(1j*list_of_pole_angles(2)) r*exp(1j*list_of_pole_angles(5))]));


L = (place(A_est', C_est', poles)');
