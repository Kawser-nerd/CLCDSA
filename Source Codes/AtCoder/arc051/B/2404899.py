n = int(input())
x = [1,2]
for i in range(n-2): x.append(x[-1]+x[-2])
if n!=1: print(x[-2],x[-1])
else: print(1,1)