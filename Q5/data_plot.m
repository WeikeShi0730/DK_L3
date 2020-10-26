%T = readtable('Q2.csv', 'HeaderLines',1);  % skips the first three rows of data
Table = csvread('Q5.csv',1);  % skips the first three rows of data

chan_size = 10;
loop_size = 5;

x = Table(1:chan_size,3);

for i = 1 : loop_size
    block_rate(:,i) = Table(chan_size*(i-1)+1:chan_size*i,7);
end

for i = 1 : loop_size
    left_rate(:,i) = Table(chan_size*(i-1)+1:chan_size*i,11);
end

hold on 
for i = 1 : loop_size
    block_p(i) = plot(x,block_rate(:,i),'Color',[0.15*i,0.16*i,0.8]);
    left_p(i) = plot(x,left_rate(:,i),'Color',[0.3,0.19*i,0.1*i]);
    block_p(i).Marker = '*';
    left_p(i).Marker = 'o';
end
hold off
grid on
title('Packet Arrival rate vs. Mean Delay');
set(gca, 'YScale', 'log');

xlabel('Number of Channels') 
ylabel('Blocking rate') 

