l = [i for i in input().split()]
l.sort()
a = int(l[-1] + l[1])
print(a + int(l[0]))