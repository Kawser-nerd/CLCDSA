X, Y = [int(i) for i in input().split()]
K = int(input())
print(X + K if Y >= K else Y + (X - (K - Y)))