from itertools import accumulate
S = input()
N = len(S)
M_cnt = S.count('M')

cnt_plus = list(accumulate([(1 if s == '+' else 0) for s in S[::-1]]))[::-1]
cnt_minus = list(accumulate([(1 if s == '-' else 0) for s in S[::-1]]))[::-1]

p = []
for i, s in enumerate(S):
    if s == 'M':
        p.append(cnt_plus[i] - cnt_minus[i])

p.sort()
ans = sum(p[M_cnt // 2:]) - sum(p[:M_cnt // 2])
print(ans)