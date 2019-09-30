from collections import Counter
n,c = (int(i) for i in input().split())
a = [int(input()) for i in range(n)]
a1,a2 = [],[]
for i in range(n):
	if i%2==0: a1.append(a[i])
	else: a2.append(a[i])
if a1.count(a1[0])==len(a1) and a2.count(a2[0])==len(a2):
	if a1[0]!=a2[0]: answer = 0
	else: answer = len(a2)*c
elif a1.count(a1[0])==len(a1) and a2.count(a2[0])!=len(a2):
	c2 = Counter(a2).most_common(2)
	if a1[0]==c2[0][0]: answer = (len(a2)-c2[1][1])*c
	else: answer = (len(a2)-c2[0][1])*c
elif a1.count(a1[0])!=len(a1) and a2.count(a2[0])==len(a2):
	c1 = Counter(a1).most_common(2)
	if a2[0]==c1[0][0]: answer = (len(a1)-c1[1][1])*c
	else: answer = (len(a1)-c1[0][1])*c
else:
	c1,c2 = Counter(a1).most_common(2),Counter(a2).most_common(2)
	if c1[0][0]!=c2[0][0]: answer = (len(a1)+len(a2)-c1[0][1]-c2[0][1])*c
	else: answer = min(len(a1)-c1[0][1]+len(a2)-c2[1][1],len(a1)-c1[1][1]+len(a2)-c2[0][1])*c
print(answer)