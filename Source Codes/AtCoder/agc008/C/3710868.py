def inpl(): return [int(i) for i in input().split()]
i, o, t, j, l, s, z = inpl() 
i, j, l = sorted([i,j,l])
if not (l-i)%2 and not (j-i)%2:
    print(o+i+j+l)
elif i == 0 and j == 1 and l == 1:
    print(o+i+j+l-2)
else:
    print(o+i+j+l-1)