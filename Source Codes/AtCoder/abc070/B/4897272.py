a = [ int(i) for i in input().split() ]
a1 = [ [a[0],0,0], [a[1],1,0], [a[2],0,1],[a[3],1,1] ]
a1 = sorted(a1)
# fs ss se fe
# fs ss fe se
# fs fe ss se
# ss fs fe se
if a1[0][2] == a1[3][2]:
    print( a1[2][0] - a1[1][0] )
elif a1[0][2] == a1[2][2]:
    print( a1[2][0] - a1[1][0] )
else:
    print(0)