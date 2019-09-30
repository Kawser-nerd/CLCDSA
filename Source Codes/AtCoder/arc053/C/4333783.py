x=[]
for _ in[0]*int(input()):a,b=map(int,input().split());x.append((a*(a<b)or 2**35-b,a,a-b))
x.sort()
t=m=0
for b,a,c in x:m=max(m,t+a);t+=c
print(m)