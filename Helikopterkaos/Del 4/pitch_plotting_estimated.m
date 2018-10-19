data = load('variables.mat');


% Estimated states vs measured states - PITCH & PITCH rate
plot(data.variables(1,:), data.variables(5,:),'blue'); % pitch rate measured
hold on;
% plot(data.variables(1,:), data.variables(11,:),'green'); % pitch rate estimated
% hold on;
plot(data.variables(1,:), data.variables(4,:),'magenta'); % pitch measurerd
hold on;
% plot(data.variables(1,:), data.variables(10,:),'black'); % pitch estimated
% hold on;
plot(data.variables(1,:), data.variables(8,:),'red'); % pitch reference
hold on;
title('Pitch measured vs. pitch estimated');
xlabel('[s]');
ylabel('[rad]');
hold off;
