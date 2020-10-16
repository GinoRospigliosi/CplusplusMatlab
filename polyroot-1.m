function z=polyroot(p)

% Set desired tolerance for iterations
tol = 1e-10;

% the derivative polynomial won't change in the loop
% so we calculate it beforehand
dp = polyder(p);

% Initialize z and f
z = 0;
f = polyval(p,z);

% Repeat Newton's method until convergence to tol
while (abs(f)>tol)
  z = z - f/polyval(dp,z);
  f = polyval(p,z);
  disp([z f])
end

% Check with p=[1 3 10 6 5 -25]
% answer is z=1
