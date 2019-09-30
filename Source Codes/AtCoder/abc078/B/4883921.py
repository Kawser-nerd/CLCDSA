X, Y, Z = map(int, input().split())

N = 0
while (N*Y+(N+1)*Z<=X):
    N+=1
print(N-1)