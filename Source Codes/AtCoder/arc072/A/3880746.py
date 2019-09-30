N = int(input())
A = list(map(int, input().split(' ')))
ans1 = 0
ans2 = 0
sum1 = 0
sum2 = 0
flag = True
for i in range(len(A)):
    sum1 = sum1 + A[i]
    sum2 = sum2 + A[i]
    flag = not(flag)
    if flag:
        if sum1 > 0:
            pass
        else:
            ans1 += abs(1-sum1)
            sum1 = 1
        if sum2 < 0:
            pass
        else:
            ans2 += abs(-1-sum2)
            sum2 = -1
    else:
        if sum2 > 0:
            pass
        else:
            ans2 += abs(1-sum2)
            sum2 = 1
        if sum1 < 0:
            pass
        else:
            ans1 += abs(-1-sum1)
            sum1 = -1
print(min(ans1, ans2))