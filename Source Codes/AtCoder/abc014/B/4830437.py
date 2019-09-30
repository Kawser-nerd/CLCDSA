n,x = map(int,input().split())
a = list(map(int,input().split()))
y = format(x,"b")
y = list(y)[::-1]
res = 0
for i in range(len(y)):
    if y[i]=="1":
        res += a[i]
print(res)