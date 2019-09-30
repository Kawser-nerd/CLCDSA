n = int(input())
a = list(map(int, input().split()))
ans = 0
pre = 0

for i in range(n-1):
    if a[i] == a[i+1]:
        if pre != 1:
            pre = 1
            ans += 1
        else:
            pre = 0
    else:
        pre = 0

print(ans)