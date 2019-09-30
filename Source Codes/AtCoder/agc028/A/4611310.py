N,M = map(int,input().split())
s = input()
t = input()
def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)
k = gcd(max(N,M),min(N,M))
lcm = N*M // gcd(max(N,M),min(N,M))
n = N//k
m = M//k
for i in range(k):
    if not s[n*i]==t[m*i]:
        print(-1)
        exit()
print(lcm)