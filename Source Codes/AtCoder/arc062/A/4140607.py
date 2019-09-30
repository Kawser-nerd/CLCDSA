N=int(input())
T,A=map(int,input().split())

for i in range(N-1):
    t,a=map(int,input().split())
    if t>=T and a>=A:
        T=t
        A=a
    elif T/t < A/a:
        if A%a==0:
            T=A//a*t
        else:
            A=(A//a+1)*a
            T=A//a*t
    else:
        if T%t==0:
            A=T//t*a
        else:
            T=(T//t+1)*t
            A=T//t*a
print(T+A)