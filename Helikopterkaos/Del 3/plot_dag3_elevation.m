data = load('variables.mat');

plot(data.variables(1,:), data.variables(7,:),'black');
hold on;
plot(data.variables(1,:), data.variables(9,:),'blue');



%plot(data.variables(1,:), data.variables(4,:),'red');
%hold on;
%plot(data.variables(1,:), data.variables(6,:),'blue');
hold off;