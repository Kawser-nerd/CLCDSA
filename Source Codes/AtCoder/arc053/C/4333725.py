x,y=[],[]
for _ in[0]*int(input()):
 a,b=map(int,input().split())
 if a<b:x.append((a,a-b))
 else:y.append((-b,a,a-b))
x.sort()
y.sort()
t=sum(a[1]for a in x)
m=x[0][0]if x else 0
for b,a,c in y:m=max(m,t+a);t+=c
print(m)