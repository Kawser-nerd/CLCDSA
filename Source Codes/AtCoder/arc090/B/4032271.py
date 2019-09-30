n,m = map(int,input().split())
#lef[i]:i???,ran[i]:i????????
lef = list(range(n+1))
ran = [0]*(n+1)

#??????????
def f(x):
    if lef[x]==x:
        return x
    #ran[x] = ran[x]+ran[lef[x]]
    lef[x],ran[x]= f(lef[x]),ran[x]+ran[lef[x]]
    
    return lef[x]

for i in range(m):
    l,r,d = map(int,input().split())
    a = f(l)
    b = f(r)
    if a == b and ran[r]-ran[l] != d:
        print("No")
        exit()
    else:
        lef[b] = a
        ran[b] = ran[l]+d-ran[r]

print("Yes")