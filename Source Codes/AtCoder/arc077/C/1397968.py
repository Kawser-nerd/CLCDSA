_,m,*A=map(int,open(0).read().split());S=l=3*m;D=[0]*l
for a,b in zip(A,A[1:]):
 b+=m*(b<a);k=b-a;S+=k
 if k>1:D[a+2]+=1;D[b+1]-=k;D[b+2]+=k-1
exec("for i in range(l):D[i]+=D[i-1]\n"*2);print(S-l-max(D[a]+D[a+m]for a in A))