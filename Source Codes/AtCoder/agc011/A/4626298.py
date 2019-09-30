n,c,k = map(int,input().split())
t = [int(input()) for _ in range(n)]
t.sort()

ans = 0
i = 0
while i < n:
    cnt = 0
    a = t[i]+k
    for j in range(c):
        if i+j < n:
            if t[i+j] <= a:
                cnt += 1
            else:
                break
        else:
            break
    ans += 1
    i += cnt
print(ans)