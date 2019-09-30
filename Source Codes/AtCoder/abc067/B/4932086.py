N,K=[int(i) for i in input().split()]
L=[int(i) for i in input().split()]
L.sort(reverse=True)
print(sum(L[:K]))