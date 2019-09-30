from sys import stdout
n = int(input())
num,ans = 0,0
for i in range(2,n+1):
	print("?",1, i)
	stdout.flush()
	a = int(input())
	if a>num: num,d = a,i
for i in range(1,n+1):
	if i!=d:
		print("?",d,i)
		stdout.flush()
		a = int(input())
		ans = max(ans,a)
print("!",ans)