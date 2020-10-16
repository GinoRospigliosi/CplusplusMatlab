%Gino Rospigliosi 
%HW#2 Section:0201
%Array for beta
beta=[0.01:0.0001:1];
%Quadratic formula for lambda
lambda=(-(alpha1*beta-alpha2)+sqrt(((alpha1*beta-alpha2).^2)-((4*beta.^(1/4)).*(alpha3*beta.^0.6))))./(2*beta.^(1/4));
%Imaginary
ilambda=imag(lambda);
%Real
rlambda=real(lambda);
%Max of imaginary lamda
[fmax,imax]=max(ilambda);
%Max imaginary lambda (imax) location in beta
beta_maxImag= beta(imax);
beta_maxImag
%Max imaginary lambda
lamIm_maxImag=max(ilambda);
lamIm_maxImag
%Zero is min of real lamda
zero=abs(rlambda);
%Zero (imin) location in beta
[fmin,imin]=min(zero);
beta_zeroReal=beta(imin);
beta_zeroReal
%Zero (imin) location in ilamda
lamIm_zeroReal=ilambda(imin);
lamIm_zeroReal
plot(rlambda,ilambda,'b',rlambda(imax),lamIm_maxImag,'ro',rlambda(imin),lamIm_zeroReal,'s k')
grid
xlabel 'Real Lambda'
ylabel 'Imaginary Lambda'
title 'Plot'