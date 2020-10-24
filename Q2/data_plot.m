%T = readtable('Q2.csv', 'HeaderLines',1);  % skips the first three rows of data
Table = csvread('Q2.csv',1);  % skips the first three rows of data

x1 = Table(1:10,3);
y1 = Table(1:10,7);

x2 = Table(12:21,3);
y2 = Table(12:21,7);

x3 = Table(22:31,3);
y3 = Table(22:31,7);

x4 = Table(32:41,3);
y4 = Table(32:41,7);

x5 = Table(42:51,3);
y5 = Table(42:51,7);

%x6 = Table(52:61,3);
%y6 = Table(52:61,7);

plot(x1,y1,'b--o');
hold on 
plot(x2,y2,'b--o');
plot(x3,y3,'b--o');
plot(x4,y4,'b--o');
plot(x5,y5,'b--o');
%plot(x6,y6,'b--o');
hold off
grid on
title('Packet Arrival rate vs. Mean Delay');

xlabel('Number of Channels') 
ylabel('Blocking rate') 

