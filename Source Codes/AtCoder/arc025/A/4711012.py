import sys
input = sys.stdin.readline

d = tuple(map(int,input().split()))
j = tuple(map(int,input().split()))
res = 0
for i in range(7):
    res += max(d[i],j[i])
print(res)