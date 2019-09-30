import math

N = int(input())
D, X = map(int, input().split())

ans = X
for i in range(N):
    A = int(input())
    ans += (D-1)//A + 1

print(ans)