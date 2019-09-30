X, A, B = map(int, input().split())
print(["A", "B"][not(abs(X-A)<abs(X-B))])