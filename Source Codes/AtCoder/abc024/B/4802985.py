n,t = (int(i) for i in input().split())
a = [int(input()) for i in range(n)]

res = t
for i in range(1, n):
    if a[i] - a[i-1] < t:
        res+=a[i]-a[i-1]
    else:
        res+=t


print(res)