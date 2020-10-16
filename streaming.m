%Gino Rospigliosi 
%HW#1 Section:0201

%rho= Density of Water
%mu= Viscosity of Water
%Re= Reynold's Number 
%d= Diameter of Microchannel
%v= Flow Velocity
%I= Streaming Current
%Z= Zeta Nonlinear Function
rho= 998; mu= 8.9*10^-4; d= 10*10^-6; 
Re= (rho*v*d)/(mu)
Z= (Re*10^-3)-1;
I= (918)*(0.91+(exp(Z)-1.2*exp(-Z))/(0.6*exp(Z)+exp(-1.19*Z)))
