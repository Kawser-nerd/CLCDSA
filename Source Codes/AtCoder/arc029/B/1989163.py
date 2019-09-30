import math
A,B = map(int,input().split())
N = int(input())
C = [0] * N
D = [0] * N
for i in range(N):
	C[i],D[i] = map(int,input().split())

res = []
for i in range(N):
	curr = False
	if A <= C[i] and B <= D[i]:
		curr = True
	if B <= C[i] and A <= D[i]:
		curr = True
	if curr == False:
		for j in range(2):
			if j == 1:
				temp = A
				A = B
				B = temp
			lo = math.atan(B/A)
			hi = math.pi/2
			mid = 0
			cnt = 0
			while lo < hi and cnt < 50:
				mid = (lo + hi) / 2
				if A * math.sin(mid) + B * math.cos(mid) < max(C[i], D[i]):
					lo = mid
				else:
					hi = mid
				cnt += 1
			if A * math.cos(lo) + B * math.sin(lo) <= min(C[i], D[i]):
				curr |= True
	if curr == True:
		res.append("YES")
	else:
		res.append("NO")

print("\n".join(map(str,res)))