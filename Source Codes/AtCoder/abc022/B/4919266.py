N = int(input())
A = [int(input()) for i in range(N)]
print(N - len(set(A)))