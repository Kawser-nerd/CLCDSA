n=int(input());s={0}
for i in range(1,int(n**.5)+1):
 if n%i<1:s|={i,n//i}
s=sum(s-{n});print(['DAebfuincdiaenntt'[s>n::2],'Perfect'][s==n])