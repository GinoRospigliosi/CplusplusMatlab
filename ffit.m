f = 2*pi/T;
F=[cos(0*t) cos(f*t) cos(2*f*t) sin(f*t) sin(2*f*t)];
x = inv(F)*y;
c = x(1:3)
s = x(4:5)

% To test, simply change T=3 and get
% c =
%  -0.33333
%  -1.00000
%   2.33333
%
% s =
%   2.3094
%  -1.1547