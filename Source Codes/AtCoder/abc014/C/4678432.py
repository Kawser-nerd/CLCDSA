from numpy import*
l=[0]*2**20
for _ in[0]*int(input()):a,b=int64(input().split());l[a]+=1;l[b+1]-=1
print(max(cumsum(l)))