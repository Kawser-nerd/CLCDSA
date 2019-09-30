from collections import Counter
s = input()
c,num,num2 = Counter(s),0,0
for i in c.most_common():
	num += (i[1]-i[1]%2)//2
	if i[1]%2==1: num2+=1
if num2==0: print(len(s))
else: print(2*(num-num%num2)//num2 +1)