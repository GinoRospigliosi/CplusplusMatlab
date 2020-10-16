function g = grav(lat)

g0 = 9.806;
gp = 9.832;
ge = 9.780;

g = g0 - .5*(gp-ge)*cosd(2*lat);

% Check with 
%  grav(30)
%  ans =  
%        9.7930

