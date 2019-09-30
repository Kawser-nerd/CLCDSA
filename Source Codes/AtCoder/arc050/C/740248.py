def F(X,D,N):Z=N and F((X*D+X)%M,D*D%M,N//2);return[Z,Z*D+X][N%2]
A,B,M=map(int,input().split());K=__import__('fractions').gcd(A,B);print(F(1,10,A)*F(1,pow(10,K,M),B//K)%M)