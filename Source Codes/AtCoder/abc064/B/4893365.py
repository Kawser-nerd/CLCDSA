n=int(input())
l=[int(i) for i in input().split()]
l.sort()
print(l[-1]-l[0])