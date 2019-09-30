n = int(input())
meat_time = [int(input()) for i in range(n)]

table1 = []
table2 = []
for i in range( round((1 << n) / 2) ):
    one = 0
    two = 0
    for j in range(n):
        if (i >> j)&1:
            one += meat_time[j]
        else:
            two += meat_time[j]
    table1.append(one)
    table2.append(two)

tmp = 0
abs_ = 100
for i,j in zip(table1,table2):
    a = abs(i-j)
    if a < abs_:
        abs_ = a
        if i < j:
            tmp = j
        else:
            tmp = i
print(tmp)