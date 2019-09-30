N, K = map(int,input().split())
A = list(map(int,input().split()))
ans = (N-1) // (K-1) if (N-1)%(K-1) == 0 else (N-1) // (K-1) + 1
print(str(ans))