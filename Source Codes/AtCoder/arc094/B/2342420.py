from math import sqrt
Q = int(input())
que = []
for i in range(Q):
    que.append(tuple(map(int, input().split())))
for q in que:
    if q[0] == q[1]:
        print(2*q[0]-2)
    else:
        a = q[0]*q[1]
        p = int(sqrt(a))
        if p*p == a:
            p -= 1
        if a > p*(p+1):
            print(2*p-1)
        else:
            print(2*p-2)