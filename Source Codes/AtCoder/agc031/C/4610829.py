n,a,b = [int(i) for i in input().split()]

#n is the point in which to check wheter the mark is different
def f(n,a,b):
    if n==1:
        return [a,b]

    mask = 1<<(n-1)

    #if biggest bit of a == that of b
    if a & mask == b & mask:
        v1 = f(n-1, a, b)
        v2 = f(n-1, a^mask, v1[1]^mask)
        ret = [a]
        ret.extend(v2)
        ret.extend(v1[1:])
        return ret        
    else:
        # biggest bit of a and b is different
        v1 = f(n-1, a, a^1)
        v2 = f(n-1, a^1^mask, b)
        v1.extend(v2)
        return v1



#exclusive or
if bin(a^b).count("1") %2==0:
    print("NO")
else:
    print("YES")
    res = f(n,a,b)
    for p in res:
        print(p, end=" ")