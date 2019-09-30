def BS(th, a):
    top = len(th)
    btm = 0

    while top > btm:
        mid = (top + btm)//2
        if th[mid] < a <= th[mid + 1]:
            return mid
        elif a <= th[mid]:
            top = mid
        else:
            btm = mid

N = int(input())
A = [int(i) for i in input().split()]

th = [0]
num_th = []
rem = []
max_i = 0
nonzeros = dict()

for i, a in enumerate(A):
    if a > th[-1]:
        th.append(a)
        num_th.append(1)
        rem.append(0)
        nonzeros[i] = max_i
        max_i += 1
    else:
        j = BS(th, a)
        if j - 1 >= 0:
            num_th[j - 1] += 1
        rem[j] += a - th[j]

for i in range(len(num_th) - 1, 0, -1):
    num_th[i - 1] += num_th[i]
'''
print(th)
print(num_th)
print(rem)
'''
for i in range(N):
    if i in nonzeros:
        ans = (th[nonzeros[i] + 1] - th[nonzeros[i]])*num_th[nonzeros[i]] + rem[nonzeros[i]]
        print(ans)
    else:
        print(0)