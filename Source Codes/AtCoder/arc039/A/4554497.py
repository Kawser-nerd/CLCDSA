a,b=map(str,input().split())
c=[[9,1],[9,0],[9,0]]
e=int(a)-int(b)
h=[]
for i in range(3):
    d=(10**(2-i))*max(c[i][0]-int(a[i]),int(b[i])-c[i][1])
    h.append(e+d)
print(max(h))