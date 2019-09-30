import math

R, C = map(int, input().strip().split())
X, Y = map(int, input().strip().split())
D, L = map(int, input().strip().split())


def ct_combi(n, r):
    if n < r:
        x = 0
    else:
        x = math.factorial(n) // (math.factorial(n - r) * math.factorial(r))
    return x


a = R - X
b = C - Y

n_1 = 0
if a and not b:
    n_1 = a+1
elif b and not a:
    n_1 = b+1
elif a and b:
    for i in range(a+1):
        for j in range(b+1):
            n_1 += 1
else:
    n_1 = 1

if X*Y != D+L:
    sum_1 = 2*ct_combi(X*(Y-1), D+L) + 2*ct_combi((X-1)*Y, D+L)
    sum_2 = ct_combi((X-2)*Y, D+L) + ct_combi((Y-2)*X, D+L) + \
        4*ct_combi((X-1)*(Y-1), D+L)
    sum_3 = 2*ct_combi((X-1)*(Y-2), D+L) + 2*ct_combi((X-2)*(Y-1), D+L)
    sum_4 = ct_combi((X-2)*(Y-2), D+L)

    sum = ct_combi(X*Y, D+L) - sum_1 + sum_2 - sum_3 + sum_4

    n_2 = sum*ct_combi(D+L, D)

else:
    n_2 = ct_combi(D+L, D)

print(n_1*n_2 % (10**9+7))