%T = readtable('Q2.csv', 'HeaderLines',1);  % skips the first three rows of data
Table = csvread('Q3.csv',1);  % skips the first three rows of data

chan_size = 15;
loop_size = 1;


%experiment
x = Table(1:chan_size,3);

for i = 1 : loop_size
    block_rate = Table(:,7);
    offer_load = Table(:,2);
end


hold on 
%block_p = plot(x,offer_load,'Color',[0.83,0.9,0.7]);
block_p = plot(x,offer_load,'r');
%block_p = plot(x(1:10),offer_load(1:10),'r');
block_p.Marker = '*';

%for j = 1 : chan_size
%    text(x(i),offer_load(i),sprintf('%.3f',block_rate(i)))
%end
%text(x(chan_size/2-1),block_rate(chan_size/2-1,i),sprintf('A = %d',offer_load(i)))

hold off
grid on
title('Number of Channels vs. offer_load on max 1% block rate');
%set(gca, 'YScale', 'log');

xlabel('Number of Channels') 
ylabel('offer_load') 
