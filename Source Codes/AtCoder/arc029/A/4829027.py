n = int(input())
t = [int(input()) for i in range(n)]
t.sort(reverse=True)
a = 0
b = 0
for i in t:
	if a <= b:
		a += i
	else:
		b += i
print(max(a,b))