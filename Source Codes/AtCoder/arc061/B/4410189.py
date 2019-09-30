i=lambda:map(int,input().split())
h,w,n=i()
r=[0,1,2]
d={} 
while n:
	a,b=i();n-=1
	for j in r:
		for k in r:
			if w>=b+k>2<a+j<=h:d[(a+j,b+k)]=d.get((a+j,b+k),0)+1
c=[0]*10
for i in d:c[d[i]]+=1
c[0]=(h-2)*(w-2)-sum(c)
print(*c,sep="\n")