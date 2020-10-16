figure(1);clf
z=roots(p);
x=min(z)-1:0.01:max(z)+1;
plot(x,polyval(p,x));
hold on
plot(z,polyval(p,z),'ro');
grid
xlabel('x');
ylabel('f(x)');
title('Polynomial graph and roots');

% Check: with p=[4  -12   -4   12    0]
% zero crossings are at -1,0,1,3 and plot
% should range from -2 to 4 on horiz axis
