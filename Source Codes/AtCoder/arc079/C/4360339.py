n = int(input())
a = list(map(int, input().split()))
p = 0
q = 0
for x in a:
    q += x
p = max(0, q-n*(n-1))
for y in range(p, q+1):
    z = 0
    for x in a:
        z += (x+y+1)//(n+1)
    if y >= z:
        print(y)
        break