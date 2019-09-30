import sys
import re


T = int(sys.stdin.readline())

for i in range(T):
    possible = True
    ss = sys.stdin.readline().split(' ')
    N = int(ss[0])
    Pd = int(ss[1])
    Pg = int(ss[2])

    if Pg == 100 and Pd < 100:
        possible = False
    if Pg == 0 and Pd != 0:
        possible = False
    if N == 0 and Pd > 0:
        possible = False

    if 0 < N and N < 100 and possible:
        found = False
        for n in range(1, N + 1):
            if n * Pd % 100 == 0:
                found = True
                break
        possible = found
        
    print('Case #{0}: {1}'.format(i + 1, 'Possible' if possible else 'Broken'))

