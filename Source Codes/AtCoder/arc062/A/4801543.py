N = int(input())            
T,A = 0,0

for _ in range(N):
    t,a = map(int,input().split())
    if T<=t and A<=a:
        T,A = t,a
    else:
        T,A = t * max((T+t-1)//t,(A+a-1)//a), a * max((T+t-1)//t,(A+a-1)//a)    
print(T+A)