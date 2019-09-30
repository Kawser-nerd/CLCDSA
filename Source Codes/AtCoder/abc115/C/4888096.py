from sys import stdin
n, k = [int(_) for _ in stdin.readline().rstrip().split()]
h = [int(stdin.readline().rstrip()) for _ in range(n)]
h.sort()
print(min(h[i+k-1] - h[i] for i in range(n-k+1)))