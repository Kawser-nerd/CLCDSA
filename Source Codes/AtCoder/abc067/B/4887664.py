n,k=map(int,input().split())
l=[int(i) for i in input().split()]
l.sort(reverse=True)
print(sum(l[:k]))