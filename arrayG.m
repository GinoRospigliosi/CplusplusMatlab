G = ( (a*s+b).*exp(-s) )./( s.^2 + c*sqrt(s) + d );
rG = abs(G)
thetaG = angle(G) 

% Check with a=b=c=sqrt(2);  d=-sqrt(2)
% and s=-[0:.5:2.5]+2j

% Answers: 
%rG    =  0.7454    1.2216    1.9373    2.8730    4.0117    5.5263
%thetaG = 2.5886    2.3657    2.1245    1.8825    1.6919    1.5687

