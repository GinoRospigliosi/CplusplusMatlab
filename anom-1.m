function f = anom(e,E)

efac = sqrt( (1+e)/(1-e) );

f = 2*atan(efac*tan(E/2));

% Check with 
%  anom(.9,2.5)
%  ans =  2.9894

