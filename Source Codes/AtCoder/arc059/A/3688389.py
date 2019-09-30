n = int(input())
a = list(map(int, input().split()))

s = sum(a)
ave_new = round(s/n)

ans = 0
for i in a:
    ans += (i-ave_new)**2

print(ans)