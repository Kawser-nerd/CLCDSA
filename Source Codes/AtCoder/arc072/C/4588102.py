n, D = map(int, input().split())
x = list(map(int, input().split()))
Q = int(input())
q = list(map(int, input().split()))

ind = [D]
for i in range(n):
	ind.append(min(ind[-1], abs(ind[-1] - x[i])))
#print(ind)

l = [1]
for i in range(n-1, -1, -1):
	if x[i] < 2*l[-1]:
		l.append(x[i] + l[-1])
	else:
		l.append(l[-1])
l = l[::-1]

for i in range(Q):
	if l[q[i]] <= ind[q[i]-1]:
		print("YES")
	else:
		print("NO")