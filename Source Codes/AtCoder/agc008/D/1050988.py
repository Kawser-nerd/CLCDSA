N = int(input())
X = list(map(int, input().split()))
A = [-1]*N*N
sorted_X = sorted(X)
first_empty = 0
last_empty = N*N-1
fail_flag = 0
for i in range(N):
	x = sorted_X[i]
	K = X.index(x)+1
	if A[x-1]==-1:
		A[x-1] = K
	else:
		print("No")
		fail_flag = 1
		break
	K_rest = K-1
	while K_rest>0:
		while True:
			if A[first_empty]==-1:
				break
			first_empty = first_empty+1
		if first_empty<x-1:
			A[first_empty] = K
			K_rest = K_rest-1
			first_empty = first_empty+1
		else:
			print("No")
			fail_flag = 1
			break
	if fail_flag==1:
		break

if fail_flag==0:
	for i in range(N-1,-1,-1):
		x = sorted_X[i]
		K = X.index(x)+1
		K_rest = N-K
		while K_rest>0:
			while True:
				if A[last_empty]==-1:
					break
				last_empty = last_empty-1
			if last_empty>x-1:
				A[last_empty] = K
				K_rest = K_rest-1
				last_empty = last_empty-1
			else:
				print("No")
				fail_flag = 1
				break
		if fail_flag==1:
			break

if fail_flag==0:
	print("Yes")
	for a in A:
		print(str(a), end=" ")