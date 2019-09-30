a=[];s='DRAW'
for i in range(int(input())):
 c=input()
 if i and(b[-1]!=c[0]or c in a):s='LWOISNE'[i%2::2];break
 b=c;a+=[c]
print(s)