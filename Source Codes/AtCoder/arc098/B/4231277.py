n = int(input())
a = list(map(int, input().split()))
s = 0
c = 0
j = 0
ans = 0
for i in range(n):
    if s + a[i] == s ^ a[i]:
        s += a[i]
        c += 1
        ans += c
    else:
        while s + a[i] != s ^ a[i]:
            s -= a[j]
            c -= 1
            j += 1
        else:
            s += a[i]
            c += 1
            ans += c
print(ans)