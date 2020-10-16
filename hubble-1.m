% Normalize c and d
chat = c/norm(c);
dhat = d/norm(d);

% Compute theta, and convert to deg for display
theta = acos(dot(chat,dhat));
theta_deg = 180*theta/pi

% Compute tau
tau = cross(chat,dhat)/sin(theta)

% Check with c=[0;2;0], d=[3;0;0]
% theta_deg = 90, tau=[0;0;-1]

