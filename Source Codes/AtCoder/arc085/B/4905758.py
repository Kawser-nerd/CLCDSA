N,Z,W=list(map(int,input().split()))
a=list(map(int,input().split()))

print(max(abs(W-a[N-1]),abs(a[N-2]-a[N-1])))