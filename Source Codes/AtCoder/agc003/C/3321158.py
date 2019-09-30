n=int(input())
a=[int(input()) for i in range(n)]
a2=set(a[::2])
a.sort()
a3=set(a[::2])
print(len(a2^a3)//2)