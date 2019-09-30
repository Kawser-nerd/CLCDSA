M, K = map(int,input().split())

R =map(int,input().split())
l = []
for k in R:
    l.append(k)
    l.sort()

r= l[-K:]

c = 0
for rr in r:
    c = (c + rr) / 2
print(c)