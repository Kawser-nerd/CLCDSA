A,B = map(int,input().split())
d = abs(A-B)
l = [0,1,2,3,2,1,2,3,3,2]
c = d//10 + l[d%10]
print(c)