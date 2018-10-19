data = load('variables.mat');


% Elevation rate vs. elevation rate ref
plot(data.variables(1,:), data.variables(7,:),'blue'); %elev rate
hold on;
plot(data.variables(1,:), data.variables(9,:),'red'); % elev rate ref
title('Elevation rate controller');
xlabel('[s]');
ylabel('[rad/s]');
hold off;

