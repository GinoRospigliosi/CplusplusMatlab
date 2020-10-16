E = 0:.001:2*pi;
fabs = abs(E - e*sin(E) - 2*pi*n);
plot(E,fabs);
grid
[fmin,imin]=min(fabs);
Emin = E(imin)

% Changing n to 41/76 in workspace, and rerunning, in
% 10 years Halley's comet should be at 
% Emin = 3.268 (and the graph of |f| should show a  
% cusp touching the 0 line at this point.)

