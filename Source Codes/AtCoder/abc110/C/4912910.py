S = [i for i in input()]
T = [i for i in input()]

judge_s, judge_t = {}, {}

idx = 0
ct = 0
for i in S:
    if judge_s.get(i):
        S[idx] = judge_s[i]
    else:
        S[idx] = ct
        judge_s[i] = ct
        ct += 1
    idx += 1

idx = 0
ct = 0
for i in T:
    if judge_t.get(i):
        T[idx] = judge_t[i]
    else:
        T[idx] = ct
        judge_t[i] = ct
        ct += 1
    idx += 1

if S == T:
    print('Yes')
else:
    print('No')