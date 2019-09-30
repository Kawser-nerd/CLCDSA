a, b, c = map(int, input().split())
X = sorted([a, b, c])[:: -1]
print(X[1])