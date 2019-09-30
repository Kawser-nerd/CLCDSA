i, o, t, j, l, s, z = (int(a) for a in input().split())

a = o + i//2*2 + j//2*2 + l//2*2
if i > 0 and j > 0 and l > 0:
    b = 3 + o + (i-1)//2*2 + (j-1)//2*2 + (l-1)//2*2
else:
    b = 0
print(max(a,b))