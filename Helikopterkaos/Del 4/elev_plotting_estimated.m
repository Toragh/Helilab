data = load('variables.mat');


% Estimated states vs measured states - ELEV & ELEV rate
plot(data.variables(1,:), data.variables(7,:),'blue'); % elev rate measured
hold on;
% plot(data.variables(1,:), data.variables(13,:),'green'); % elev rate estimated
% hold on;
plot(data.variables(1,:), data.variables(6,:),'magenta'); % elev measurerd
hold on;
% plot(data.variables(1,:), data.variables(12,:),'black'); % elev estimated
% hold on;
plot(data.variables(1,:), data.variables(9,:),'red'); % elev reference
hold on;
title('Elevation measured vs. elevation estimated');
xlabel('[s]');
ylabel('[rad]');
hold off;
