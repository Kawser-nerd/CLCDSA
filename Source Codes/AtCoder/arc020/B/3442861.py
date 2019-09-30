n,c,*v=map(int,open(0).read().split())
a=[[0,i]for i in range(11)]
b=[[0,i]for i in range(11)]
for t in v[::2]:a[t][0]+=1
for t in v[1::2]:b[t][0]+=1
a=sorted(a)[::-1]
b=sorted(b)[::-1]
if a[0][1]==b[0][1]:i=n-max(a[0][0]+b[1][0],a[1][0]+b[0][0])
else:i=n-a[0][0]-b[0][0]
print(i*c)