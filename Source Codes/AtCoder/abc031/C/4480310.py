N=int(input())
a=list(map(int,input().split()))

S=sum(a)
taka=[]
aoki=[]
T=-10000
A=-10000
ta=0
ao=0

for i in range(N):
    for j in range(N):
        if i==j:
            pass
        else:
            
            for k in range(min(i,j),max(i,j)+1):
                if (k-min(i,j))%2==0:
                    ta+=a[k]
                else:
                    ao+=a[k]
            if A<ao:
                A=ao
                T=ta
                #print(ao,ta,j)
            
            ta=0
            ao=0
    taka.append(T)
    aoki.append(A)
    T=-10000
    A=-10000
print(max(taka))