function E=kepler(e,n)

tol = 1e-10;
E = pi/2;

f = E - e*sin(E) - 2*pi*n;

while (abs(f)>tol)
  df = 1-e*cos(E);
  E = E - f/df;
  f = E - e*sin(E) - 2*pi*n;
end

% Check with foo = kepler(.967,26/76)
% should give foo = 2.6262

