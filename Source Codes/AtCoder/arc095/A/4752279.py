N = int(input())
x = list(map(int, input().split()))
x_s = sorted(x)
m_l, m_r = x_s[N // 2 - 1], x_s[N // 2]
d = dict()
for i, s in enumerate(x_s):
    if i < N // 2:
        d[s] = m_r
    else:
        d[s] = m_l
for i in x:
    print(d[i])