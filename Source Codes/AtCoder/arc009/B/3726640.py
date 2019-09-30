b = input().split()
n = int(input())
a = [list(input()) for i in range(n)]
for i in range(n):
    su = 0
    l = len(a[i])
    for j in range(l):
        su += b.index(a[i][j])*10**(l-j-1)
    a[i] = [a[i]]+[su]
a.sort(key = lambda x:x[1])
for i in range(n):
    for j in a[i][0]:
        print(j, end = "")
    print()