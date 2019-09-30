n,k=map(int,input().split())
L=[int(i) for i in input().split()]
print(sum(sorted(L)[-k:]))