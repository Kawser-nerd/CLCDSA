N=int(input())
def gcd(a,b):
    while b:
        a,b=b,a%b
    return a
def lcm(a,b):
    return a*b//gcd(a,b)

T=[]
for i in range(N):
    T.append(int(input()))

if N==1:
    print(T[0])
else:
    a=lcm(T[0],T[1])
    for i in range(N):
        a=lcm(a,T[i])
    print(a)