n=int(input())
d,x=map(int,input().split())
a=[int(input()) for i in range(n)]
ans=0
for i in a:
    tmp=1
    while True:
        if tmp*i+1<=d:
            a=tmp*i+1
            #print(a)
            tmp+=1
        else:
            #print("tmp",tmp)
            ans+=tmp
            break
print(ans+x)