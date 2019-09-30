A, B, X = map(int, input().split())
print(["YES", "NO"][not(X <= A + B and A <= X)])