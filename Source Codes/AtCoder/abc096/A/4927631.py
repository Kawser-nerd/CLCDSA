l = [int(i) for i in input().split()]
print(l[0] if l[0] <= l[1] else l[0] - 1)