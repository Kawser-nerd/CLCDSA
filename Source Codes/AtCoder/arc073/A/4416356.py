n,T=map(int,input().split())
t=[int(i) for i in input().split()]
t =[0]+t
time=t[-1]
for a in range(1,n+1):
    if t[a]-t[a-1]>T:
        time-=(t[a]-t[a-1])-T
print(time+T)