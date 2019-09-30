from collections import defaultdict
for t in xrange(int(raw_input())):
    dig = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
    order = [0, 2, 6, 7, 5, 4, 1, 8, 9, 3]
    od = ['Z', 'W', 'X', 'S', 'V', 'U', 'O', 'G', 'I', 'R']
    cnt = defaultdict(lambda: 0)
    ansd = defaultdict(lambda: 0)
    ans = ''
    for j in raw_input().strip(): cnt[j] += 1
    for ind, i in enumerate(order):
        ansd[i] = cnt[od[ind]]
        for j in dig[i]: cnt[j] -= ansd[i]
    for i in ansd: ans += str(i) * ansd[i]
    print 'Case #' + str(t + 1) + ': ' + ans
