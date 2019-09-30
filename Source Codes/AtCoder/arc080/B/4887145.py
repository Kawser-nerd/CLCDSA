H,W = map(int,input().split())
N = int(input())
a = list(map(int,input().split()))
l = []
for color,m in enumerate(a,1):
    l += [color]*m
for i in range(H):
    k = l[:W]
    l = l[W:]
    if i%2 != 0:
        k.reverse()
    print(*k)