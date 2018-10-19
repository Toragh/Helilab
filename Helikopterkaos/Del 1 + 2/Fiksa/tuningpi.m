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
w_0 = 3;  % resonance frequency
k_f = 0.13872; % motor force constant
k_rp = -1; % travel regulator constant


%tuning variables
%vd
% Kpptune = 100;
% Kpitune = 5;

%vs
Kpptunevs = 10;
Kpitunevs = 1;
