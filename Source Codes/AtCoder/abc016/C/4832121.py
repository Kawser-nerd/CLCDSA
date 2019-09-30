n,m=map(int,input().split())
s=[set([i]) for i in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    s[a-1].add(b-1)
    s[b-1].add(a-1)

for i in s:
    l=set()
    for j in i:
        l |= s[j]
    print(len(l-i))