%
%  Homework 1 solution: drag_of_a_sphere.m
%
%  Requires that the following variables have been defined in the workspace:
%   rho (density), mu (viscosity), D (diameter), V (velocity)
%
%  Note that all quantities are in SI (metric) units here!
%

%  Reynolds number
Re = rho * V * D / mu

%  Drag coefficient
Cd = 24/Re * ( 1 + 0.27*Re )^0.43 + 0.47 * ( 1 - exp(-0.04*Re^0.38) )

%  Drag force
A = pi*D^2/4 ;
Fd = Cd * 0.5*rho*V^2*A



