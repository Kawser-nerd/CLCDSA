I=lambda:list(map(int,input().split()))
n,k=I()
z=[I()for _ in[0]*n]
z.sort()
a=10**20
for i in range(n):
 for j in range(i+k-1,n):l=sorted(t[1]for t in z[i:j+1]);a=min(a,*[(z[j][0]-z[i][0])*(v-u)for u,v in zip(l,l[k-1:])])
print(a)