n,a=map(int, input().split())
x=list(map(int, input().split()))
x=[i-a for i in x]
d={0:1}
for i in x:
    for j,k in list(d.items()):
        d[i+j]=d.get(i+j,0)+k
print(d[0]-1)
#sample code.