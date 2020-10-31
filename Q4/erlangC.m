clear all;

syms i
lambda = 2;
X = 0.5;
A = lambda * X;
N = 2;
t = 50/60;

rho = A/N;
Pw = vpa((A^N/factorial(N))/(A^N/factorial(N) + (1-rho)*symsum(A^i/factorial(i),i,0,N-1)))
Tw = vpa(Pw)*X/(N*(1-rho))
W = 1-vpa(Pw) * exp(-(N-A)*t/X)