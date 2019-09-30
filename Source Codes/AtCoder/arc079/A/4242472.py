n,m=map(int,input().split())
c=[[]for i in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    c[a-1].append(b)
    c[b-1].append(a)
for a in c[0]:
    if n in c[a-1]:
        print("POSSIBLE")
        break
else:
    print("IMPOSSIBLE")