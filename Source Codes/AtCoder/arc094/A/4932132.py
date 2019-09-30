X,Y,Z=sorted(list(map(int,input().split(' '))))
print((Z-Y)+(Y-X)//2+2*((X-Y)%2))