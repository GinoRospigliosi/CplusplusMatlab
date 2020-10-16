function x=jacobi(A,b,N)

% Note: the quantities below don't change
% during the calculations in the loop,
% so it is best to put them *before* the
% loop to avoid unnecessarily repeating them
D=diag(diag(A));
S=A-D;
invD = inv(D);  

% Initialize x
x=b;
% Run the iterations the specified number of times
for k=1:N
  x = invD*(b-S*x);
end

% For the test case; take
% A=[5 -1 2; 1 3 1; -2 2 -5];
% b = [1;-2;3];
% Then jacobi(A,b,2) should give
%   ans = [0.61;-0.56;-0.6480]
% while jacobi(A,b,20) should give
%   ans = [0.5;-0.5;-1.0] 
% which agrees with the exact solution.

