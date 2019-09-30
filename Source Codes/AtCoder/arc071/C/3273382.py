s = input()
t = input()
q = int(input())
sl,tl = len(s),len(t)
sa,sb,ta,tb = [0]*(sl+1),[0]*(sl+1),[0]*(tl+1),[0]*(tl+1)
for i in range(sl):
	if s[i]=="A": sa[i+1],sb[i+1] = sa[i]+1,sb[i]
	else: sa[i+1],sb[i+1] = sa[i],sb[i]+1
for i in range(tl):
	if t[i]=="A": ta[i+1],tb[i+1] = ta[i]+1,tb[i]
	else: ta[i+1],tb[i+1] = ta[i],tb[i]+1
for _ in range(q):
	a,b,c,d = (int(i) for i in input().split())
	if (sa[b]-sa[a-1]-sb[b]+sb[a-1]-ta[d]+ta[c-1]+tb[d]-tb[c-1])%3: print("NO")
	else: print("YES")