T = int(input())

for case in range(1, T + 1):
    t = input().split()
    B = int(t[0])
    M = int(t[1])
    if M > 2 ** (B - 2):
        print('Case #{0}: IMPOSSIBLE'.format(case))
        continue
    else:
        print('Case #{0}: POSSIBLE'.format(case))
    ans = []
    for i in range(B):
        ans.append([])
        for j in range(B):
            ans[i].append('0')
        for j in range(i + 1, B - 1):
            ans[i][j] = '1'
    for i in range(B - 2, 0, -1):
        now = 2 ** (i - 1)
        if M >= now:
            M -= now
            ans[i][B - 1] = '1'
    assert(M <= 1)
    if M >= 1:
        ans[0][B - 1] = '1'
    for line in ans:
        print(''.join(line))

