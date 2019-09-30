A, B, C = input().split()
l = sorted([A, B, C], reverse=True)
print(int(l[0] + l[1]) + int(l[-1]))