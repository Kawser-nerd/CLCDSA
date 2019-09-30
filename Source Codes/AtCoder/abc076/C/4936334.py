S = input()
T = input()
t = len(T)
indices = []
for i in range(len(S) - t + 1):
    for j, s in enumerate(S[i:i+t]):
        if s == '?':
            continue
        if s != T[j]:
            break
    else:
        indices.append(i)
if len(indices) == 0:
    print('UNRESTORABLE')
else:
    cand = []
    for ind in indices:
        ans = ''
        for i, s in enumerate(S):
            if i == ind:
                ans += T
            elif ind < i < ind + t:
                continue
            elif s == '?':
                ans += 'a'
            else:
                ans += s
        cand.append(ans)
    cand = sorted(cand)
    print(cand[0])