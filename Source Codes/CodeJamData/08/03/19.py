from sys import stdin as input_file
from sys import stdout as output_file
from math import pi, sqrt

num_segments = 1000000

def readline(file):
    return file.readline().rstrip('\n')

def hit_probability(fly_radius, racquet_outer_radius, racquet_thickness, string_radius, string_gap):
    racquet_thickness += fly_radius
    string_radius += fly_radius
    string_gap -= 2 * fly_radius
    if string_gap <= 0.0:
        probability = 1.0
    else:
        hit_area = 0.0
        delta = racquet_outer_radius / num_segments
        string_diameter = 2 * string_radius
        unit = string_diameter + string_gap
        lower = string_radius
        upper = string_radius + string_gap
        outer_square = racquet_outer_radius ** 2
        inner_square = (racquet_outer_radius - racquet_thickness) ** 2
        for i in xrange(num_segments):
            x = (i + 0.5) / num_segments * racquet_outer_radius
            x_square = x * x
            difference = inner_square - x_square
            x_div, x_mod = divmod(x, unit)
            hit_length = sqrt(outer_square - x_square)
            if (difference > 0) and (x_mod > lower) and (x_mod < upper):
                sqrt_difference = sqrt(difference)
                hit_length -= sqrt_difference
                y_div, y_mod = divmod(sqrt_difference, unit)
                hit_length += y_div * string_diameter
                if y_mod < lower:
                    hit_length += y_mod
                elif y_mod < upper:
                    hit_length += string_radius
                else:
                    hit_length += y_mod - string_gap
            hit_area += hit_length * delta
        probability = hit_area / (pi / 4 * racquet_outer_radius ** 2)
    return probability

num_cases = int(readline(input_file))
for case_num in xrange(num_cases):
    entries = readline(input_file).split()
    fly_radius = float(entries[0])
    racquet_outer_radius = float(entries[1])
    racquet_thickness = float(entries[2])
    string_radius = float(entries[3])
    string_gap = float(entries[4])
    probability = hit_probability(fly_radius, racquet_outer_radius, racquet_thickness, string_radius, string_gap)
    output_file.write('Case #%d: %f\n' % (case_num + 1, probability))
