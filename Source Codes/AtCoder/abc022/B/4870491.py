N = int(input())
A = [int(input()) for i in range(N)]
print(len(A) - len(set(A)))