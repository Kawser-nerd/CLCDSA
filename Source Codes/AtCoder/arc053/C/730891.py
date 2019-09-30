n= int(input())
t1=[]
t2=[]
ts =0
for i in range(n):
    a,b = map(int,input().split())
    if a >=b:
        t2.append([a,b])
    else :
        t1.append([a,b])
    
t2.sort(key=lambda x: x[1], reverse=True)
t1.sort(key=lambda x: x[0])

t2.sort(key=lambda x: x[1], reverse=True)
t1.sort(key=lambda x: x[0])
t=t1+t2
tn =0
for e in t:
    tn += e[0]
    ts = max(ts,tn)
    tn  -=e[1]
    
print(ts)