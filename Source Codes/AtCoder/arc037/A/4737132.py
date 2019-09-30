import sys
input = sys.stdin.readline

n = int(input())
m = tuple(map(int,input().split()))
res = 0
for e in m:
    if e >= 80:
        continue
    res += 80-e
print(res)