data = load('variables.mat');


% Estimated states vs measured states - TRAVEL & TRAVEL rate
plot(data.variables(1,:), data.variables(3,:),'blue'); % travel rate measured
hold on;
plot(data.variables(1,:), data.variables(15,:),'green'); % travel rate estimated
hold on;
plot(data.variables(1,:), data.variables(2,:),'magenta'); % travel measurerd
hold on;
plot(data.variables(1,:), data.variables(14,:),'black'); % travel estimated
hold on;
% plot(data.variables(1,:), data.variables(9,:),'red'); % travel reference
% hold on;
title('Travel measured vs. travel estimated');
xlabel('[s]');
ylabel('[rad]');
hold off;
