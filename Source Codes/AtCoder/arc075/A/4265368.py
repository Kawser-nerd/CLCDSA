n=int(input())
a=[int(input())for i in range(n)]
a.sort()
c=0
p=sum(a)
if p%10!=0:
    print(p)
else:
    for i in range(n):
        if a[i]%10!=0:
            break
        else:
            c+=1
    print(0 if c==n else p-a[i])