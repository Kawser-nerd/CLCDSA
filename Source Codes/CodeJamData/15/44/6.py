#!/usr/bin/env python3

T = int(input())
for case in range(1, T+1):
    R, C = [int(i) for i in input().split()]

    a1  = [1, 1, 0, 1, 1]
    a3  = [0, 0, 1, 0, 1]
    a4  = [0, 0, 0, 1, 0]
    a6  = [0, 0, 1, 0, 1]
    a12 = [0, 0, 0, 0, 0]

    for n in range(5, R+1):
        a1.append(a1[n-3])
        a3.append(a3[n-3]+a1[n-4]+3*a3[n-4])
        a4.append(a4[n-3]+a1[n-5]+4*a4[n-5])
        a6.append(a6[n-3]+9*a6[n-4]+a1[n-4]+3*a3[n-4])
        a12.append(a12[n-3]+3*a4[n-4]+10*a12[n-4]+a1[n-5]+3*a3[n-5]+4*a4[n-5]+6*a6[n-5]+12*a12[n-5])

    ans = a1[R] + a1[R-2]
    if C %  3 == 0: ans +=  a3[R] +  a3[R-2]
    if C %  4 == 0: ans +=  a4[R] +  a4[R-2]
    if C %  6 == 0: ans +=  a6[R] +  a6[R-2]
    if C % 12 == 0: ans += a12[R] + a12[R-2]
    ans %= 1000000007

    print("Case #{}: {}".format(case, ans))

