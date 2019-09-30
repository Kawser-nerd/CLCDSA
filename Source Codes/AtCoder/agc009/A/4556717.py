N = int(input())
A = []
B = []
for _ in range(N):
    a,b = [int(i) for i in input().split()]
    A.append(a)
    B.append(b)

ans = 0
for i in range(1,N+1):
    A[-i] += ans
    if A[-i]%B[-i] != 0:
        ans += B[-i]-A[-i]%B[-i]

print(ans)