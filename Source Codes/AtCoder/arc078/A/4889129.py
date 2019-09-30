n=int(input());a=list(map(int,input().split()));b=[0]
for i in a:b.append(b[-1]+i)
b=b[1:];s=b[-1];mi=abs(b[0]-(b[-1]-b[0]))
for i in range(n-1):mi=min(abs(b[i]-(b[-1]-b[i])),mi)
print(mi)