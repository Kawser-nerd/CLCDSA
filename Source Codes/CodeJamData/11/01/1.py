#!/usr/bin/python
#b.py
#Author: James Damore
#Created on: May 06, 2011
#Time-stamp: <2011-05-06 19:56:30>
#~/python/codeJam/b.py

def run_command(commands):
    bPos = oPos = 1
    bTime = oTime = 0
    time = 0
    for c in commands:
        if c[0] == 'O':
            minTime = abs(oPos - c[1]) - time + oTime
            time += max(minTime, 0) + 1
            oTime = time
            oPos = c[1]
        else:
            minTime = abs(bPos - c[1]) - time + bTime
            time += max(minTime, 0) + 1
            bTime = time
            bPos = c[1]
    return time
        
def read_input():
    line = raw_input().split()[1:]
    commands = [(line[2*i], int(line[2*i + 1])) for i in range(len(line)//2)]
    return run_command(commands)
    

numCases=input()
for i in range(1, numCases+1):
    #read_input()
    output = read_input()
    print "Case #%d:" % i, output
