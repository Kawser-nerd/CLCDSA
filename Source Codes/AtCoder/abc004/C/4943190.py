N = int(input())
N %= 30

X = ['1', '2', '3', '4', '5', '6']

for i in range(N):
    a = i%5
    b = i%5 + 1
    X[b], X[a] = X[a], X[b] 

print(''.join(X))