d, g = map(int, input().split())

problems = []
ans = 0

for i in range(d):
    p, c = map(int, input().split())
    problems.append(((i+1)*100, p, c))
    ans += p

for mask in range(1 << d):
    solved_amount = 0
    my_score = 0
    for i in range(d):
        score, occ, bonus = problems[i]
        if mask & (1 << i) > 0:
            solved_amount += occ
            my_score += score * occ + bonus

    for x in range(d-1, -1, -1):
        if my_score >= g:
            break

        if (mask & (1 << x)) > 0:
            continue
        score, occ, bonus = problems[x]
        for _ in range(occ):
            solved_amount += 1
            my_score += score
            if my_score >= g:
                break

    if my_score >= g:
        ans = min(ans, solved_amount)

print(ans)