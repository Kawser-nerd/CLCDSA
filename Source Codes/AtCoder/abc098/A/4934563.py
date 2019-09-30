A, B = map(int, input().split())
a = A + B
if A * B > a:
    a = A * B
if A - B > a:
	a = A - B
print(a)