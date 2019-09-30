N = int(input())
T = list(map(int, input().split()))
M = int(input())
P = 0
X = 0
for i in range(M):
	P, X = map(int, input().split())
	print(sum(T) - T[P-1] + X)