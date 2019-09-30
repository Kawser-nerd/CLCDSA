D, G = map(int, input().split())

probs = []
ans = 0

for i in range(D):
    p, c = map(int, input().split())
    probs.append(((i+1) * 100, p, c))
    ans += p

for mask in range(1 << D):  # d?????????2**d?????
    solved = 0   # ????
    my_score = 0
    for i in range(D):
        score, occ, bonus = probs[i]  # score?100?????, occ????,
        if mask & (1 << i) > 0:
            solved += occ
            my_score += score * occ + bonus  # ??????????

    for x in range(D - 1, -1, -1):
        if my_score >= G:
            break
        if (mask & (1 << x)) > 0:
            continue
        score, occ, bounDs = probs[x]
        for _ in range(occ):  # ???, ???????????
            solved += 1
            my_score += score
            if my_score >= G:
                break
    if my_score >= G:
        ans = min(ans, solved)

print(ans)