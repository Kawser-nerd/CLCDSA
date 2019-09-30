from collections import defaultdict

T = int(raw_input())

for t in range(T):
    s = raw_input()
    count = [0] * 10
    count[0] = s.count('Z')
    count[2] = s.count('W')
    count[4] = s.count('U')
    count[6] = s.count('X')
    count[8] = s.count('G')
    letters = (
        count[0] * 'ZERO' +
        count[2] * 'TWO' +
        count[4] * 'FOUR' +
        count[6] * 'SIX' +
        count[8] * 'EIGHT'
    )

    alpha = defaultdict(int)
    for c in s:
        alpha[c] += 1
    for c in letters:
        alpha[c] -= 1

    count[1] = alpha['O']
    count[3] = alpha['H']
    count[5] = alpha['F']
    count[7] = alpha['S']
    count[9] = alpha['I'] - count[5]
    ans = ''
    for i in range(10):
        for j in range(count[i]):
            ans += str(i)
    print 'Case #%d: %s' % (t+1, ans)
