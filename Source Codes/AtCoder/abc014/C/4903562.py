import numpy as np

n=int(input())
memo=[]
for _ in range(n):
    a,b = list(map(int, input().split()))
    memo.append((a,-1))
    memo.append((b,+1))

memo.sort()
print(-np.array([x[1] for x in memo]).cumsum().min())