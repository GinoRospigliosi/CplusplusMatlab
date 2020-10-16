avg_spots = mean(nspots)
std_spots = std(nspots)

[max_spots,max_index] = max(nspots);
max_spots
year_of_max = year(max_index)
month_of_max = month(max_index)

[min_spots,min_index] = min(nspots);
min_spots
year_of_min = year(min_index)
month_of_min = month(min_index)

% Outputs:
% <Given:>
% avg_spots =  47.702
% std_spots =  40.805
% max_spots =  170.10
% year_of_max =  2000
% month_of_max =  7
% <Check:>
% min_spots = 0
% year_of_min =  2009
% month_of_min =  8

