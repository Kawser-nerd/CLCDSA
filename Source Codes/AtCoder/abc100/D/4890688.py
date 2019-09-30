n,m=map(int,input().split())
k=["+","-"]
d=[[]for i in range(8)]
for i in range(n):
    a,b,c=map(str,input().split())
    for j in range(2):
        for h in range(2):
            for p in range(2):
                s=4*j+2*h+p
                d[s].append(eval(k[j]+a+k[h]+b+k[p]+c))
h=0
for i in range(8):
    h=max(h,sum(sorted(d[i])[n-m:]))
print(h)