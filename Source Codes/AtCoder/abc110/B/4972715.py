"""
map(int,input().split())

X = input().split()
x = []
for i in range(0,len(X)):
    x.append(X[i])

"""
N,M,X,Y = map(int,input().split())

x = input().split()
xls = []

for n in range(0,N):
    xls.append(int(x[n]))

y = input().split()
yls = []

for n in range(0,M):
    yls.append(int(y[n]))

xls.sort()
yls.sort()

if xls[len(xls)-1] >= yls[0]:
    print("War")
elif yls[0] <= X:
    print("War")
elif xls[len(xls)-1] >= Y:
    print("War")
else:
    print("No War")