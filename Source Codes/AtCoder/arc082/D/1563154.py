# F
# input
from bisect import bisect
X = int(input())
K = int(input())
r_list = [0] + list(map(int, input().split()))

Q = int(input())
query_list = [list(map(int, input().split())) for _ in range(Q)]


MmRL_list = []

# M:max, m:min, R:min_a(M), L:max_a(m)
M = X
m = 0
R = X
L = 0

MmRL_list.append([M, m, R, L])

for i in range(K):
    M_ = M
    m_ = m
    R_ = R
    L_ = L
    lag = r_list[i+1] - r_list[i]
    # update
    if i % 2 == 0:
        if M_ - lag < 0:
            M = 0
            R = 0
        else:
            M = M_ - lag
            R = R_
        if m_ - lag < 0:
            m = 0
            L = L_ + lag - m_
        else:
            m = m_ - lag
            L = L_
    else:
        if M_ + lag > X:
            M = X
            R = R_ - (M_ + lag - X)
        else:
            M = M_ + lag
            R = R_
        if m_ + lag > X:
            m = X
            L = X
        else:
            m = m_ + lag
            L = L_
    MmRL_list.append([M, m, R, L])
        

# print(MmRL_list)
for q in range(Q):
    t, a = query_list[q]
    j = bisect(r_list, t) - 1
    # find status then
    M, m, R, L = MmRL_list[j]
    if a <= L:
        a_ = m
    elif a >= R:
        a_ = M
    else:
        a_ = m + (a - L)
    t_ = t - r_list[j]
    if j % 2 == 0:
        res = max(a_ - t_, 0)
    else:
        res = min(a_ + t_, X)
    print(res)