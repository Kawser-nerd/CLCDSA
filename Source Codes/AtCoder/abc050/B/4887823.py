N = int(input())
T = list(map(int, input().split()))
M = int(input())
sumT = sum(T)
for i in range(M):
    p, x = map(int, input().split())
    print(sumT + x - T[p-1])