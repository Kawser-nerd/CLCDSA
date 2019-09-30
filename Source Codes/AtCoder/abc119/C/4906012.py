n,a,b,c = map(int, input().split())
l = [int(input()) for _ in range(n)]

def find(i, A, B, C):
	if i == n:
		return abs(A-a) + abs(B-b) + abs(C-c) if min(A, B, C) > 0 else 9999999999999999999999999999
	else:
		return min(
			find(i + 1, A       , B       , C       ),
			find(i + 1, A + l[i], B       , C       ) + (10 if A > 0 else 0),
			find(i + 1, A       , B + l[i], C       ) + (10 if B > 0 else 0),
			find(i + 1, A       , B       , C + l[i]) + (10 if C > 0 else 0),
		)

print(find(0, 0, 0, 0))