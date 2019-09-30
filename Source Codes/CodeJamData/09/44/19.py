'''
Google Code Jam 2009
Round 2
D.

@author: Samuel Spiza
'''

import math
#fileName = "D-practice.in"
fileName = "D-small-attempt0.in"
#fileName = "D-large.in"
file = open(fileName, "r")

def dst(a, b):
    return (a[0]-b[0])**2 + (a[1]-b[1])**2

def group(case, i, j):
    a = case[i]
    b = case[j]
    arr = [[], []]
    while 0 < len(case):
        p = case.pop()
        if dst(p, a) < dst(p, b):
            arr[0].append(p)
        else:
            arr[1].append(p)
    return arr
    
def minradius(case):
    i = 0
    high = [0, 0, 0]
    while i < len(case) - 1:
        j = i + 1
        while j < len(case):
            d = dst(case[i], case[j])
            if high[2] < d:
                high = [i, j, d]
            j = j + 1
        i = i + 1
    print case
    print high
    return (math.sqrt(high[2]) + case[high[0]][2] + case[high[1]][2])/2
    
def findmin(case):
    if len(case) == 1:
        return case[0][2]
    i = 0
    high = [0, 0, 0]
    while i < len(case) - 1:
        j = i + 1
        while j < len(case):
            d = dst(case[i], case[j])
            if high[2] < d:
                high = [i, j , d]
            j = j + 1
        i = i + 1
    grouped = group(case, high[0], high[1])
    return max([minradius(g) for g in grouped])
    
i = -1
j = 0
string = ""

cases = []
for line in file:
    if i == -1:
        C = int(line.strip())
        i = 1
    elif i == 0:
        j = j + 1
        cases.append([])
        N = int(line.strip())
        i = N + 1
    else:
        cases[-1].append([int(x) for x in line.strip().split()])
    i = i - 1

file.close()

z = 1
for case in cases:
    string = string + "Case #" + str(z) + ": " + str(findmin(case)) + "\n"
    z = z + 1




    
file = open(fileName.rsplit(".", 1)[0] + ".out", "w")
file.write(string.strip())
file.close()
