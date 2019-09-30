n = int(input())
a = list(map(int, input().split()))
m = -5000
for x in range(n):
    k = -5000
    l = -5000
    for y in list(range(x)) + list(range(x+1,n)):
        p = sum(a[min(x, y):max(x, y)+1:2])
        q = sum(a[min(x,y)+1: max(x,y)+1:2])
        if q > l:
            k, l = p, q
    m = max(m, k)
print(m)