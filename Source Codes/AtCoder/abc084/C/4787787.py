n = int(input())
l = []
for _ in range(n-1):
    l.append([int(i) for i in input().split()])
for j in range(n):
    l_ = l[j:]
    c = 0
    for i in range(n-1-j):
        if c <= l_[i][1]:
            c = l_[i][1]
        elif (c % l_[i][2] != 0):
            c = (c // l_[i][2] + 1) * l_[i][2]
        else:
            c = (c // l_[i][2]) * l_[i][2]
        c += l_[i][0]
    print(c)