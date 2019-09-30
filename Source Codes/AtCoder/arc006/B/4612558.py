from sys import stdin
input = stdin.readline

n, l = map(int, input().split())
L = []
for _ in range(l+1):
    L_ = list(input())
    L.append(L_)
now = L[l].index("o")

for i in range(l-1, -1, -1):
    if L[i][now-1] == "-":
        now -= 2
    elif L[i][now+1] == "-":
        now += 2

print(now//2 + 1)