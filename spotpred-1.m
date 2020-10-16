dm = 12*(year-1992)+month-1;
ns=70+70*cos(2*pi*dm/132+pi/3);

figure(1);clf
plot(dm,nspots,'bo');
hold on
plot(dm,ns,'r-');

diff = ns-nspots;

avg_err = mean(diff(1:200))
std_err = std(diff(1:200))
max_abs_err = max(abs(diff(1:200)))

% Outputs
% <Check>
% avg_err =  4.4728
% std_err =  19.985
% max_abs =  59.321

