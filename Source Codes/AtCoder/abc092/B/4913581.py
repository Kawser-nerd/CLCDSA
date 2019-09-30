N = int(input())
D, X = map(int, input().split())

ans = X
for i in range(N):
    A = int(input())
    X += (D+A-1)//A
print(X)