function fmax = findForces(W, theta1, theta2)
%
%  ENME202, HW5
%  Solve for tension forces in a system of 3 cables.
%  Input:
%    - weight (in Newton) as a scalar value
%    - angle1 (in radians) as a scalar value
%    - angle2 (in radians) as an array
%  Output:
%    - largest of the two forces (in Newton) as an array
%

%  Find length of input data
N = length(theta2) ;

%  Loop over all input parameters
for k=1:N,

  %  Right hand side b
  b = [ 0 ; W ] ;

  %  Matrix A
  A = [ -cos(theta1) cos(theta2(k)) ; sin(theta1) sin(theta2(k)) ] ;

  %  Solve
  f = inv(A) * b ;

  %  Find the largest, store in array
  fmax(k) = max(f) ;
end


%  if called by findForces(10, 30*pi/180, [15 35 70]*pi/180), the answer is 13.6603    9.5555    8.7939
%  if called by findForces(20, 20*pi/180, [20 40 60]*pi/180), the answer is 29.2380   21.7013   19.0838

