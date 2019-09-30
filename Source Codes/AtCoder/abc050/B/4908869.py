N = int(input())
T = list(map(int, input().split()))
M = int(input())
s = sum(T)
for i in range(M):
    p, x = map(int, input().split())
    print(s - T[p - 1] + x)