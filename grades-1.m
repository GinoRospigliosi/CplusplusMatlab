function [na,nb,nc,nd]=grades(x)

N = length(x);
m = mean(x);

% Initialize counters for each grade level
na = 0;
nb = 0;
nc = 0;
nd = 0;

% Test each element of x against grade criteria
% and increment appropriate counter
for k=1:N
  if (x(k)>m+15)      % A grade
    na = na+1;
  elseif (x(k)>=m)    % B grade
    nb = nb+1;
  elseif (x(k)>=m-15) % C grade
    nc = nc+1;
  else                % D grade
    nd = nd+1;
  end
end

% Check with t=1:125; x=60+45*cos(t/2).*sin(2*t)
% Should give na=34, nb=30, nc=26, nd=35
