N = int(input())
A = [int(i) for i in input().split()]

ans = 0
for i in range(N):
    if A[i] < 80:
        ans += (80 - A[i])
        
print(ans)