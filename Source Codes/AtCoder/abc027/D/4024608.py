s = input()

n = len(s)
plus = [0] * n  # plus[i]: s[i]??????+???
minus = [0] * n  # minus[i]: s[i]??????-???

diff = [0] * n

p_cnt = 0
m_cnt = 0
for w in s:
    if w == "+":
        p_cnt += 1
    elif w == "-":
        m_cnt += 1

for i, w in enumerate(s):
    if w == "+":
        p_cnt -= 1
    elif w == "-":
        m_cnt -= 1
    plus[i] = p_cnt
    minus[i] = m_cnt
    diff[i] = p_cnt - m_cnt

d = []
for i, w in enumerate(s):
    if w == "M":
        d.append(diff[i])

d.sort()

print(-sum(d[:len(d)//2]) + sum(d[len(d)//2:]))