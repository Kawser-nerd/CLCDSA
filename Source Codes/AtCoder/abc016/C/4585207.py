n,m=map(int,input().split())
d=[[]for i in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    d[a-1].append(b-1)
    d[b-1].append(a-1)
c=0
for i in range(n):
    for j in range(n):
        for h in range(n):
            if i!=j:
                if j not in d[i]:
                    if h in d[i]:
                        if j in d[h]:
                            c+=1
                            break
    else:
        print(c)
        c=0