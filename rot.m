% Compute the "elementary" rotation matrices for each of 
% the individual Euler angles
Rx=[1 0 0;0 cos(phi) sin(phi);0 -sin(phi) cos(phi)];
Ry=[cos(theta) 0 -sin(theta); 0 1 0; sin(theta) 0 cos(theta)];
Rz=[cos(psi) sin(psi) 0; -sin(psi) cos(psi) 0; 0 0 1];

% Multiply above results together to get the complete
% rotation matrix for this set of Euler angles
% Note: multiplication order is important with matrices!
R=Rx*Ry*Rz;

% Check case: 
% phi = pi/2; theta=pi/2; psi=-pi; rot
% Then should get R*[1;-2;3] = [-3; -1; -2]

