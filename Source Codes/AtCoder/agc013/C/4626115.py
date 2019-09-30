N,L,T = map(int, input().split())
X = [0]*N
W = [0]*N
for n in range(N):
    X[n],W[n] = map(int, input().split())
index = 0
#after T
for n in range(N):
    X[n] += ((-1)**(W[n]+1))*T
    index += X[n]//L
    X[n] %= L
index %= N
X.sort()
X = X[index:] + X[:index] #No.1 wo hajimeni mottekuru.
for n in range(N):
    print(X[n])