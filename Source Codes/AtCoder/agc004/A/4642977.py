a,b,c = map(int,input().split())
d = sorted([a,b,c])
x = d[-1]//2
y = d[-1] - d[-1]//2
print(abs(x-y)*d[0]*d[1])