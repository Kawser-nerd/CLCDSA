N = int(input())
P = [int(input()) for i in range(N)]

M = int(max(P))

print(int(sum(P) - M + M/2))