n = int(input())
x,r,ans = [],n,0
for _ in range(n):
	s = input()
	r = s.rfind(".",0,r)
	if r+1: ans+=1
	else: r = n
print(ans)