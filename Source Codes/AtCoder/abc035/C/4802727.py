from itertools import accumulate
N, Q = map(int, input().split())
a = []
for i in range(Q):
    a.append(list(map(int, input().split())))
b = [0]*(N+1)
for i in range(Q):
    b[a[i][0]-1] += 1
    b[a[i][1]] += -1
ans = ''
for x in list(accumulate(b))[:-1]:
    if x%2 == 0:
        ans += '0'
    else:
        ans += '1'
print(ans)