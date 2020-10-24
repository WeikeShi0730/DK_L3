%T = readtable('Q2.csv', 'HeaderLines',1);  % skips the first three rows of data
Table = csvread('Q3.csv',1);  % skips the first three rows of data

x = Table(:,2);
y = Table(:,3);

plot(x,y,'b--o');

title('Packet Arrival rate vs. Mean Delay');

xlabel('Offered load (erlang)') 
ylabel('Number of channels') 

