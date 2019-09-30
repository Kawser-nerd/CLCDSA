N=int(input())
p = list(map(int,input().split()))
buf = 0
count = 0
for i in range(N):
    if i+1==p[i]:
        buf+=1
    else:
        count+=int((buf+1)/2)
        buf=0
count+=int((buf+1)/2)   
print(count)