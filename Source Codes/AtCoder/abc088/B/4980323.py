n=int(input())
L=[int(i) for i in input().split()]
print(2*sum(sorted(L)[::-2])-sum(L))