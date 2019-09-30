N, D = list(map(int,input().split()))
d = list(map(int,input().split()))
Q = int(input())
q = list(map(int,input().split()))

a = [D for i in range(N)]
b = [1 for i in range(N+1)]
for i in range(1,N):
	a[i] = min(abs(a[i-1]-d[i-1]),a[i-1])
for i in range(N)[::-1]:
	if d[i]//2 < b[i+1]:
		b[i] = b[i+1] + d[i]
	else:
		b[i] = b[i+1]

res = ""
for i in q:
	if a[i-1] < b[i]:
		res+="NO"
	else:
		res+="YES"
	res+="\n"

print(res)