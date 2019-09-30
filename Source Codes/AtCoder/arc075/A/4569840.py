a,*b=map(int,open(0).read().split())
c=[i for i in b if i%10==0]
d=sorted([i for i in b if i%10!=0])
if len(d)==0:
    print(0)
    exit()
for i in range(len(d)):
    if sum(d)%10==0:
        d[i]=0
    else:
        break
print(sum(d)+sum(c))