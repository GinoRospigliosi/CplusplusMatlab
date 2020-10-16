%GinoRospigliosi
%HW#3 Section:0201
%Load Data
load mouse
%Plot Data and Polyfit
figure(1);clf
plot(t,x,'bd')
grid 
title 'Position of a Scared Mouse vs Time'
xlabel 'Time (sec)'
ylabel 'Position (cm)'
p1=polyfit(t,x,4);
hold on
plot(t,polyval(p1,t),'r') 
%Standard Deviation
N=length(t);
yi=x(1:1:N);
xi=t(1:1:N);
ybar=(1/N)*sum(yi);
yhat=polyval(p1,xi);
inner1=(yi-yhat).^2;
inner2=(yi-ybar).^2;
stdr=sum(inner1);
stdt=sum(inner2);
R=sqrt(1-(stdr/stdt))
%Manual Derivatives
Velocity=4*p1(1)*t.^3+3*p1(2)*t.^2+2*p1(3)*t+p1(4);
Acceleration=3*4*p1(1)*t.^2+2*3*p1(2)*t+1*2*p1(3);
Jerk=4*3*2*p1(1)*t+6*p1(2);
t_maxAccel=-6*p1(2)/(24*p1(1))
%Acceration Polynomial
paccel=[12*p1(1) 6*p1(2) 2*p1(3)];
maxAccel=polyval(paccel, t_maxAccel)
plot(t_maxAccel,maxAccel, 'k+')