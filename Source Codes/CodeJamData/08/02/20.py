from sys import stdin as input_file
from sys import stdout as output_file

def readline(file):
    return file.readline().rstrip('\n')

def time_to_int(time):
    hour_str, min_str = time.split(':')
    return int(hour_str) * 60 + int(min_str)

def get_earliest_trip(trips, current_time=-1):
    earliest_trip = None
    for trip in trips:
        if (trip[0] >= current_time) and ((earliest_trip is None) or (trip[0] < earliest_trip[0])):
            earliest_trip = trip
    return earliest_trip

num_cases = int(readline(input_file))
for case_num in xrange(num_cases):
    turnaround_time  = int(readline(input_file))
    line = readline(input_file)
    num_trips = [int(entry) for entry in line.split()]
    trips = [[], []]
    for station_num in xrange(2):
        for trip_num in xrange(num_trips[station_num]):
            time_strs = readline(input_file).split()
            trip = (time_to_int(time_strs[0]), time_to_int(time_strs[1]))
            trips[station_num].append(trip)
    num_trains = [0, 0]
    while any(trips):
        earliest_trips = [get_earliest_trip(trips[0]), get_earliest_trip(trips[1])]
        if (earliest_trips[1] is None) or ((earliest_trips[0] is not None)
                and (earliest_trips[0][0] < earliest_trips[1][0])):
            station_num = 0
        else:
            station_num = 1
        num_trains[station_num] += 1
        next_trip = earliest_trips[station_num]
        while next_trip:
            trips[station_num].remove(next_trip)
            station_num = 1 - station_num
            current_time = next_trip[1] + turnaround_time
            next_trip = get_earliest_trip(trips[station_num], current_time)
    output_file.write('Case #%d: %d %d\n' % (case_num + 1, num_trains[0], num_trains[1]))
