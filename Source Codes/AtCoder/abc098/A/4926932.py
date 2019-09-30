s = [int(i) for i in input().split()]
l = [s[0] + s[1], s[0] - s[1], s[0] * s[1]]
print(max(l))