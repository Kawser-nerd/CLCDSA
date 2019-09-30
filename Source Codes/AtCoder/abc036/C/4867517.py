n=int(input())
a=[]
c=[]
for _ in range(n):
    x=int(input())
    c.append(x)
    a.append(x)
c=sorted(set(c))
b={}
for i in range(len(c)):
    b[c[i]]=i
for k in a:
    print(b[k])