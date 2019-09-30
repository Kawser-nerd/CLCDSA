n = int(input())
a,b = map(int,input().split())
ans=0
if n<=a or a>b:
    pass
elif a<b:
    ans=1
elif  a==b:
    if n%(a+1)!=0:
        pass
    else:
        ans=1
print('Takahashi' if ans==0 else 'Aoki')