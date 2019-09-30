N = int(input())
T = [int(x) for x in input().split()]
M = int(input())

s = 0
for i in T:
    s += i

for i in range(M):
    P, X = map(int, input().split())

    print(s - T[P-1] + X)