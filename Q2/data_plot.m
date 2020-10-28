%T = readtable('Q2.csv', 'HeaderLines',1);  % skips the first three rows of data
Table = csvread('Q2.csv',1);  % skips the first three rows of data

chan_size = 10;
loop_size = 6;


%experiment
x = Table(1:chan_size,3);

for i = 1 : loop_size
    block_rate(:,i) = Table(chan_size*(i-1)+1:chan_size*i,7);
    offer_load(i) = Table(chan_size * (i),2);
end

%calc
%for i = 1 : loop_size
    %for I = 1 : x(i)
        %B(:,i) = (offer_load(i).^x(i)/factorial(x(i)))/sum(offer_load(i).^I/factorial(I),I,0,x(i));
    %end
%end

hold on 
for i = 1 : loop_size
    block_p(i) = plot(x,block_rate(:,i),'Color',[0.1*i,0.13*i,0.6]);
    block_p(i).Marker = '*';
    text(x(chan_size/2-1),block_rate(chan_size/2-1,i),sprintf('A = %d',offer_load(i)))
end;

hold off
grid on
title('Number of Channels vs. Blocking rate');
set(gca, 'YScale', 'log');

xlabel('Number of Channels') 
ylabel('Blocking rate') 

