n = int(input())
a = list(map(int, input().split()))
s = 0
j = 0
ans = 0
for i in range(n):
    while s + a[i] != s ^ a[i]:
        s -= a[j]
        j += 1
    else:
        s += a[i]
        ans += i - j + 1
print(ans)