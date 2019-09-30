c1 = list(map(int, input().split()))
c2 = list(map(int, input().split()))
c3 = list(map(int, input().split()))

flag = 'No'
for i in range(c1[0] + 1):
    a1 = i
    b1 = c1[0] - a1
    b2 = c1[1] - a1
    b3 = c1[2] - a1
    a2 = c2[0] - b1
    a3 = c3[0] - b1

    c22 = a2 + b2
    c23 = a2 + b3
    c32 = a3 + b2
    c33 = a3 + b3

    if (c2[1] - c22) ** 2 + (c2[2] - c23) ** 2 + (c3[1] - c32) ** 2 + (c3[2] - c33) ** 2 == 0:
         flag = 'Yes'
print(flag)