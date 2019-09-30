n = int(input())
a = list(map(int, input().split()))
ma = -100000000
mi = 100000000
for i in range(n):
    if a[i] > ma:
        ma = a[i]
        ma_index = i
    if a[i] < mi:
        mi = a[i]
        mi_index = i
ans = []
if ma >= -mi:
    for i in range(n):
        ans.append((ma_index,i))
    for i in range(n-1):
        ans.append((i,i+1))
else:
    for i in range(n):
        ans.append((mi_index,i))
    for i in range(n-1):
        ans.append((n-1-i,n-2-i))
print(len(ans))
for x in ans:
    print(x[0]+1,x[1]+1)