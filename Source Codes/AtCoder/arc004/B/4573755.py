from sys import stdin
input = stdin.readline

n = int(input())
L = []
for i in range(n):
    d = int(input())
    L.append(d)
ma = sum(L)
if 2*max(L) > sum(L):
    mi = 2*max(L) - sum(L)
else:
    mi = 0

print(ma)
print(mi)