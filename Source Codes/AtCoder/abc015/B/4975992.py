n=int(input())
a=[int(i) for i in input().split()]
print(int((sum(a)-1)//(n-a.count(0)))+1)