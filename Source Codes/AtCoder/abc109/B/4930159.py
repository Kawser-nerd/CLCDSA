N=int(input())
W=[input() for _ in range(N)]
his=set()
ok=True
lc=W[0][0]
for w in W:
	if w in his or lc != w[0]:
		ok=False
		break
	his.add(w)
	lc=w[len(w)-1]
print("Yes" if ok else "No")