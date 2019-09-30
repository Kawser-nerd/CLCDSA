n, m = map(int, input().split())
a = [int(input()) for i in range(m)]

is_used = [False]*n
ans = []

for i in range(m)[::-1]:
    if not is_used[a[i]-1]:
        ans.append(a[i])
        is_used[a[i]-1] = True

for i in range(n):
    if not is_used[i]:
        ans.append(i+1)
        
for i in range(n):
    print(ans[i])