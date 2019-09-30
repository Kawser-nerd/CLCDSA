N = int(input())
T, A = map(int, input().split())
H = list(map(int, input().split()))

X = []
for i in range(N):
    X.append(abs(A - (T - H[i] * 0.006)))
print(X.index(min(X)) + 1)