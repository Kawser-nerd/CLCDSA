n,m,d=map(int,input().split())
a=list(map(int,input().split()))
x=[i for i in range(n)]
for t in a[::-1]:
    x[t-1],x[t]=x[t],x[t-1]
yy=[x] #yy[i]=y**(2**i)
for i in range(len(bin(d))-3):
    t=[yy[-1][yy[-1][i]] for i in range(n)]
    yy.append(t)
y=[i for i in range(n)]
t=bin(d)[2::]
for i in range(len(t)):
    if t[i]=="1":
        y=[y[yy[-i-1][j]] for j in range(n)]
z=[i for i in range(n)]
z=[z[y[i]] for i in range(n)]
for t in z:
    print(int(t)+1)