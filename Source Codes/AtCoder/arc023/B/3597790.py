R, C, D = map(int, input().split())
ans = 0
for i in range(R):
    A = list(map(int, input().split()))
    for k in range(0+(D-i)%2,min(C-1,D-i)+1,2):
        ans = max(ans, A[k])
print(ans)