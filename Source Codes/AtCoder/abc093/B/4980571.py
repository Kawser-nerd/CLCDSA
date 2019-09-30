a,b,k=map(int,input().split())
N=[int(i) for i in range(a,min(a+k,b+1))]
M=[int(i) for i in range(max(a,b-k+1),b+1)]
print(*sorted(set(M+N)),sep="\n")