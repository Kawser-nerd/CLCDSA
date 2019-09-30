n,k = (int(i) for i in input().split())
s = input()
if n<k*2: print("NO")
else:
	x,t = [],[0]*26
	for i in range(k): t[ord(s[i])-97]+=1
	x.append((tuple(t),k-1))
	for i in range(k,n):
		t[ord(s[i-k])-97]-=1
		t[ord(s[i])-97]+=1
		x.append((tuple(t),i))
	x,i,f = sorted(x),0,0
	while i<n-k:
		for j in range(i+1,n-k+1):
			if x[i][0]!=x[j][0]:
				i = j
				break
			elif x[j][1]-x[i][1]>=k:
				f = 1
				break
			elif j==n-k: i = n-k
		if f: break
	if f: print("YES")
	else: print("NO")