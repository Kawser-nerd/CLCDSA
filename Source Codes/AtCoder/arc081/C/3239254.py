from bisect import bisect
s = input()
x,y,k,p = [1]*26,[len(s)],1,[[1] for i in range(26)]
for i in range(len(s)-1,-1,-1):
	n = ord(s[i])-97
	x[n] = 0
	p[n].append(-i)
	if sum(x)==0:
		k,x = k+1,[1]*26
		y.append(i)
y,num,ans = y[::-1],0,""
for i in range(k):
	for j in range(97,123):
		if chr(j) not in s[num:y[i]]: break
	ans+=chr(j)
	b = bisect(p[j-97],-y[i])-1
	num = -p[j-97][b]+1
print(ans)