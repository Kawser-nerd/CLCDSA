n=int(input())
x=[]
u=[]
for i in range(n):
    xu = list(map(str,input().split()))
    x.append(float(xu[0]))
    mon = xu[1]
    if mon == "JPY":
        u.append(1)
    else:
        u.append(380000)
s = 0
for i in range(n):
    s = s + x[i]*u[i]
print(s)