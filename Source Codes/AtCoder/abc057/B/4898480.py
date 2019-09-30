n,m = map(int,input().split())
stud = []
for i in range(n):
    a,b = map(int,input().split())
    stud.append([a,b])
dist = [ 1e9 for i in range(n) ]
at = [ 0 for i in range(n) ]
for j in range(m):
    a,b = map(int,input().split())
    for i in range(n):
        d = abs(a - stud[i][0]) + abs(b - stud[i][1])
        if d < dist[i]:
            dist[i] = d
            at[i] = j+1

for i in at:
    print(i)