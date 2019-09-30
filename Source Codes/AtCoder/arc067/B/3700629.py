N, A, B = map(int,input().split())
X = [int(i) for i in input().split()]
X.insert(0,0)

ans = 0
for i in range(2, N+1):
    ans += min(A *(X[i] -X[i-1]), B)

print(ans)