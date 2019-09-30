def ma():return map(int, input().split())#a,b,c,d or n,k
a,b = ma()
print((a-1)*b+a*(b-1))