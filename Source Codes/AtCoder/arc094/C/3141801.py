N = int(input())
c = -1
s = 0
for i in range(N):
    ai,bi = map(int,input().split())
    s += ai
    if ai > bi:
        if c == -1:
            c = bi
        if bi < c:
            c = bi
if c == -1:
    print(0)
else:
    print(s-c)