n,m=map(int, input().split())
a=[list(map(int, input().split())) for i in range(m)]
d={}
for i,j in a:
    d[i]=d.get(i,set())|{j}
    d[j]=d.get(j,set())|{i}
path=a[0][:]
sp=set(path)
while d[path[-1]]-sp:
    t=d[path[-1]]-sp
    t=t.pop()
    path.append(t)
    sp.add(t)
path=path[::-1]
while d[path[-1]]-sp:
    t=d[path[-1]]-sp
    t=t.pop()
    path.append(t)
    sp.add(t)
print(len(path))    
print(*path)