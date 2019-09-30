N,M,X,Y = map(int,input().split())
x = list(map(int,input().split()))
y = list(map(int,input().split()))

if min(Y,min(y)) > max(X,max(x)):
    print('No War')
else:
    print('War')