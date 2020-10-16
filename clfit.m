% Have the students issue the commands 
% clear and close all before running!!

load clref   % change to cltest for testing

figure(1);clf
plot(al,cl,'ro');
xlabel('Alpha (deg)');
ylabel('CL');
title('Lift curve data and fit')
grid
hold on

p2 = polyfit(al,cl,2);
pvals2 = polyval(p2,al);
plot(al,pvals2);

[max2err,idx]=max(abs(cl-pvals2));
max2err
al2err = al(idx)
r2=roots(p2)

% Root at negative alpha is where CL=0, hence where no lift is generated!

p3 = polyfit(al,cl,3);
pvals3 = polyval(p3,al);
plot(al,pvals3,'g-');

[max3err,idx]=max(abs(cl-pvals3));
max3err
al3err = al(idx)
r3=roots(p3)

% For clref: max cubic error is 0.046 at alpha=16
% Cubic roots are 24.79, -26.42, and -3.46
% The last of these is physically where CL=0

% For cltest stats are:
% max2err = 0.334 at alpha=16, CL=0 at -4.55
% max3err = 0.211 at alpha=14, CL=0 at -3.844
