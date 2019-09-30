N,K,X,Y = map(int, open(0).read().split())
print(K*X+(N-K)*Y if N>K else N*X)