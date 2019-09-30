a=[int(i) for i in input().split(' ')]
a.sort()
print(sum(a) - 2*a[1])