a,b,c,d,e = list(map(int, input().split()))

l=[e+d+c,e+d+c,e+d+b,d+c+b,e+c+b,e+d+a,e+c+a,d+c+a]
L=list(set(l))
L.sort(reverse=True)
print(L[2])