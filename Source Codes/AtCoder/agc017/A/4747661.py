n,p=map(int,input().split());a=list(map(int,input().split()));b=[0,0]
for i in a:b[i%2]+=1
if 0==b[1]:print(2**n*((p+1)%2))
else:print(2**(n-1))