n = int(input())
a = [ int(x) for x in input().split() ]

ans1, ans2 = 0, 0
sum_v = 0

# ??????
for i in range(len(a)):
    sum_v += a[i]
    # sumv := minus
    if i % 2 == 0:
        if sum_v >= 0:
            ans1 += abs(sum_v)+1
            sum_v = -1
    # sumv := plus
    else:
        if sum_v <= 0:
            ans1 += abs(sum_v)+1
            sum_v = 1

sum_v = 0

# ???plus
for i in range(len(a)):
    sum_v += a[i]
    # sumv := minus
    if i % 2 == 0:
        if sum_v <= 0:
            ans2 += abs(sum_v)+1
            sum_v = 1
    # sumv := plus
    else:
        if sum_v >= 0:
            ans2 += abs(sum_v)+1
            sum_v = -1

print (min(ans1, ans2))