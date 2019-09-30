#!/usr/bin/python

# Run by:
#     cat input | b.py

import sys
from math import sqrt

l = sys.stdin.readline()
n = int(l)

for i in range(n):
    print 'Case #%d:' % (i+1,),

    l = sys.stdin.readline()
    turnaround = int(l)

    l = sys.stdin.readline()
    departures = [int(x) for x in l.split()]

    queue = []
    for i in range(departures[0]):
        l = sys.stdin.readline()
        time = [int(x) for x in l.split()[0].split(':')]
        depart = time[0]*60 + time[1]
        time = [int(x) for x in l.split()[1].split(':')]
        arrive = time[0]*60 + time[1]
        queue.append((depart, 'A', 1))
        queue.append((arrive + turnaround, 'B', -1))
    for i in range(departures[1]):
        l = sys.stdin.readline()
        time = [int(x) for x in l.split()[0].split(':')]
        depart = time[0]*60 + time[1]
        time = [int(x) for x in l.split()[1].split(':')]
        arrive = time[0]*60 + time[1]
        queue.append((depart, 'B', 1))
        queue.append((arrive + turnaround, 'A', -1))

    queue.sort()
    
    max_trains = {'A': 0, 'B': 0}
    num_trains = {'A': 0, 'B': 0}
    
    for (time, station, change) in queue:
        num_trains[station] += change
        if num_trains[station] > max_trains[station]:
            max_trains[station] = num_trains[station]

    print max_trains['A'], max_trains['B']
    