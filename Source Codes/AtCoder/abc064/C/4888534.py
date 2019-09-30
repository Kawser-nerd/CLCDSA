from sys import stdin

n = int(input())
a = list(map(int, stdin.readline().split()))

rate = [0]*8
f = 0

for i in range(n):
    if 3199 < a[i]:
        f += 1
    else:
        rate[int((a[i]/400))] = 1

s = sum(rate)
min = s if 0 < s else 1
max = s+f

print(min, max)