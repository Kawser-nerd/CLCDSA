N = int(input())
a = list(map(int,input().split()))
ans = 0
now = a[0]
i = 1
while i < N:
    if now == a[i]:
        ans += 1
        if i == N-1:
            break
        now = a[i+1]
        i += 2
        
    else:
        now = a[i]
        i += 1
print(ans)