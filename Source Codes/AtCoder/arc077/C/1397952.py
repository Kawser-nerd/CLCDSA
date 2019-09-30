n,m,*A=map(int,open(0).read().split());l=3*m;D=[0]*l;S=0
for a,b in zip(A,A[1:]):
 b+=m*(b<a);k=b-a;S+=k
 if k>1:D[a+2]+=1;D[b+1]-=k;D[b+2]+=k-1
exec("for i in range(1,l):D[i]+=D[i-1]\n"*2);print(S-max(D[a]+D[a+m]for a in A))