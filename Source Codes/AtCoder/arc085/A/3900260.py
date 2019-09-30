N,M = list(map(int,input().split()))
X=2**M
print(int((100*(N-M)+1900*M)*X))