from itertools import product
from collections import defaultdict
n = int(input())
s = input()
sa,sb = s[:n],s[n:][::-1]
a,b,ans = defaultdict(int),defaultdict(int),0
for i in product(range(2),repeat=n):
	wa,wb,wa2,wb2 = "","","",""
	for j in range(n):
		if i[j]: wa,wb = wa+sa[j],wb+sb[j]
		else: wa2,wb2 = wa2+sa[j],wb2+sb[j]
	a[(wa,wa2)]+=1
	b[(wb,wb2)]+=1
while a:
	p,q = a.popitem()
	ans+=q*b[p]
print(ans)