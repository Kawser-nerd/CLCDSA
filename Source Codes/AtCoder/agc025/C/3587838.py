n = int(input())
L,R = [0],[0]
for _ in range(n):
	l,r = (int(i) for i in input().split())
	L.append(l)
	R.append(r)
L,R,ans = sorted(L)[::-1],sorted(R),0
for i in range(n+1):
	if L[i]>R[i]: ans+=L[i]-R[i]
	else: break
print(ans*2)