a = list(map(int, input().split()))
ans = (a[0]//2)*2 + a[1] + (a[3]//2)*2 + (a[4]//2)*2
if a[0] and a[3] and a[4]:
    odd = sum((a[0]%2, a[3]%2, a[4]%2))
    ans += 3 if odd == 3 else 1 if odd == 2 else 0
print(ans)