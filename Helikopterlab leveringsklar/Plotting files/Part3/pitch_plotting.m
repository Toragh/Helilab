data = load('variables.mat');

% Pitch vs. pitch ref
plot(data.variables(1,:), data.variables(4,:),'blue'); % pitch 
hold on;
plot(data.variables(1,:), data.variables(8,:),'red'); % pitch ref
title('Pitch controller');
xlabel('[s]');
ylabel('[rad]');
hold off;

