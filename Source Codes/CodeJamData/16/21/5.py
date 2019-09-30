from collections import defaultdict
def solve():
    s = raw_input().strip()
    dic = defaultdict(int)
    for c in s:
        dic[c] += 1
    ans = []
    key = [('0', 'Z', 'ZERO'), ('2', 'W', 'TWO'), ('4', 'U', 'FOUR'), ('5', 'F', 'FIVE'), ('3', 'R', 'THREE'), ('6', 'X', 'SIX'), ('7', 'S', 'SEVEN'), ('8', 'G', 'EIGHT'), ('1', 'O', 'ONE'), ('9', 'I', 'NINE')]
    for d, u, f in key:
        i = dic[u]
        ans += [d] * i
        for c in f:
            dic[c] -= i
    ans.sort()
    return ''.join(ans)
    
T = int(raw_input())
for t in xrange(T):
    print "Case #%d:" % (t + 1), solve()
