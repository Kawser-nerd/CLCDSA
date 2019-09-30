N,K = map(int,input().split())
a = list(map(int,input().split()))
ex = 0
for i in range(N-K):
    ex += (a[i]+a[-1-i])*(N-K-i)

print((N-K+1)*sum(a)-ex)