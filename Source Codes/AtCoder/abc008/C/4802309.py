n = int(input())
C = [int(input()) for i in range(n)]

ans = 0
for i in range(n):
    cnt = 0
    for j in range(n):
        if i != j and C[i]%C[j] == 0:
            cnt += 1
    if cnt % 2 == 1:
        ans += 0.5
    else:
        ans += (cnt+2)/(2*cnt+2)

print(ans)