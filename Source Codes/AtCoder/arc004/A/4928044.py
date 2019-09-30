import math
import sys
input=sys.stdin.readline

N = int(input())
setlist = [input() for _ in range(N)]
result = 0.0

for s1 in setlist:
    x1, y1 = map(int, s1.split())
    for s2 in setlist:
        x2, y2 = map(int, s2.split())
        tmp = math.sqrt((x2-x1)**2+(y2-y1)**2)
        if result < tmp:
            result = tmp

print(result)