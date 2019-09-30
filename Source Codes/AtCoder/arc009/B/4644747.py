from sys import stdin
input = stdin.readline

B = list(map(int, input().split()))
n = int(input())
L = []
for i in range(n):
    a = input()
    a = a[:-1]
    c = ""
    for st in a:
        c += str(B.index(int(st)))
    L.append([int(c), a])
L.sort()
for i in range(n):
    print(L[i][1])