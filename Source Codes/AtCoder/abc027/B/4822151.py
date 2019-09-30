n = int(input())
a = list(map(int, input().split()))

if sum(a) % n != 0:
    print(-1)
    exit()

m = sum(a) // n

ans = 0
temp = -1
c = 0
for i in range(n):
    if temp == -1:
        if a[i] != m:
            temp = a[i]
            ans += 1
            c = 1
    else:
        c += 1
        temp += a[i]
        if temp == c * m:
            temp = -1
        else:
            ans += 1

print(ans)