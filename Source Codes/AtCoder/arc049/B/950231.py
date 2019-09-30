from itertools import combinations as c
n = int(input())
resolve = [list(map(int, input().split())) for x in range(n)]
maxtime = 0
for (x1, y1, c1), (x2, y2, c2) in c(resolve, 2):
    x = x1 + (abs(x2 - x1) * c2) / (c1 + c2)
    y = y1 + (abs(y2 - y1) * c2) / (c1 + c2)
    maxtime = max(maxtime, c1 * max(abs(x1 - x), abs(y1 - y)))
print(maxtime)