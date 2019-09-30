n = int(input())
a = list(map(int,input().split()))
ans = 0
for i in range(1,n-2):
    if a[i-1] == a[i]:
        a[i] = -i
        ans += 1
    elif a[i+1] == a[i]:
        a[i+1] = - (i+1)
        ans += 1
if a[-1] == a[-2]:
	ans += 1
print(ans)