n,k=map(int, input().split())
h=sorted([int(input()) for _ in range(n)])
print(min(h[i] - h[i-k+1] for i in range(k-1, n)))