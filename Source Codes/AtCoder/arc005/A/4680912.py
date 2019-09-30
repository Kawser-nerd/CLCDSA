n=int(input())
w=input().split()
ct=0
for i in range(n-1):
  if w[i]=='TAKAHASHIKUN' or w[i]=='Takahashikun' or w[i]=='takahashikun':
    ct+=1
if w[n-1]=='TAKAHASHIKUN.' or w[n-1]=='Takahashikun.' or w[n-1]=='takahashikun.':
  ct+=1
print(ct)