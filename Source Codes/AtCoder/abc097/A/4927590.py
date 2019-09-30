l = [int(i) for i in input().split()]
print("Yes" if ((abs(l[0] - l[1]) <= l[3]) & (abs(l[1] - l[2]) <= l[3])) or (abs(l[0] - l[2]) <= l[3]) else "No")