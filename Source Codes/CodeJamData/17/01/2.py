tnum = int(raw_input())

for ti in range(tnum):
    s, k = raw_input().split()[:2]
    s = [0 if c=='+' else 1 for c in s]
    k = int(k)
    ans = 0
    for i in range(len(s)-k+1):
        if s[i]==1:
            ans += 1
            for j in range(k):
                s[i+j]=1-s[i+j]
    print 'Case #{}: {}'.format(ti+1, ans if sum(s)==0 else 'IMPOSSIBLE')
