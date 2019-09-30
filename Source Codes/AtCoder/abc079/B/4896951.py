l = [2,1]
n = int(input())
for i in range(2,n+1):
    l.append( l[-1] + l[-2] )
print(l[n])