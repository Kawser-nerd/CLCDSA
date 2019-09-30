N=int(input())
a=list(map(int,input().split()))

b=sorted(a)

a1=b[(N-1)//2]
a2=b[(N-1)//2+1]

for i in a:
    if(i<=a1):
        print(a2)
    else:
        print(a1)