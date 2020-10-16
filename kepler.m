E = 0:.001:2*pi;
f = E - e*sin(E) - 2*pi*n;
plot(E,f);

% Change n to 41/76 in workspace, and rerun.
% In 10 years Halley's comet should be at 
% E = 3.27 (i.e. graph of f should cross zero 
% at about this value of E)

