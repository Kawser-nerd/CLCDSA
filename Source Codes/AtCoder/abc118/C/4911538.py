N = int(input())
a = list(map(int, input().split()))
a.sort()
G = a[0]
for i in range(1, N, 1):
	A = a[i]
	while A % G != 0:
		A, G = G, A % G
print(G)