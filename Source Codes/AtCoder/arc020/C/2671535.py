N=int(input())
S =[]
for i in range(N):
    a,l=input().split()
    S.append([a,int(l)])
B =int(input())
k=0
for i in range(N):
    k += len(S[i][0])*S[i][1]

def f(y,z,b):
    if z==1:
        return 1
    elif z%2==0:
        t = pow(y,z//2,b)
        return ((1+t) * f(y,z//2,b))%b
    else:
        return (1+y*f(y,z-1,b))%b
    
ans = 0
for i in range(N):
    t = len(S[i][0])
    k-=len(S[i][0])*S[i][1]
    r = 10**t
    K = f(r,S[i][1],B)
    U=pow(10,k,B)
    K*=int(S[i][0])
    K%=B
    K*=U
    K%=B
    ans += K
    ans %=B
print(ans)