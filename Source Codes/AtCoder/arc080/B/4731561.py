h,w=map(int,input().split())
n=int(input())
a=list(map(int,input().split()))
p=1
k=0
s=0
for i in range(h):
    c=""
    for j in range(w*(i%2)-i%2,w*(1-i%2)-i%2,(1 if i%2==0 else -1)):
        if i%2==1:
            c=str(p)+" "+c
        else:
            c+=str(p)+" "
        k+=1
        if a[p-1]==k:
            p+=1
            k=0
    else:
        print(c[:-1])