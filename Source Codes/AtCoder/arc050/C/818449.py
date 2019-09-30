def F(D,N,X=1):Z=N and F(D*D%M,N//2,(X*D+X)%M);return[Z,Z*D+X][N%2]
A,B,M=map(int,input().split());K=__import__('fractions').gcd(A,B);print(F(10,A)*F(pow(10,K,M),B//K)%M)