n,m = map(int,input().split())
SUM = 0
c = [0]*(m+10)
for i in range(n):
    l,r,s = map(int,input().split())
    c[l-1] += s
    c[r] -= s
    SUM += s
for i in range(m+5):
    c[i+1] += c[i]
print(SUM-min(c[:m]))