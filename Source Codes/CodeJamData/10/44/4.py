#!/usr/bin/env python
import math

def solve(c):
    n, m = map(lambda x: int(x), raw_input().split())
    g = []
    buckets = []
    
    area = -1
    
    for i in xrange(n):
        g.append(map(lambda x: int(x), raw_input().split()))
    
    for i in xrange(m):
        buckets.append(map(lambda x: int(x), raw_input().split()))
    
    ans = []
    for b in buckets:
        l1 = ((b[0] - g[0][0])**2 + (b[1] - g[0][1]) ** 2) ** 0.5
        l2 = ((b[0] - g[1][0])**2 + (b[1] - g[1][1]) ** 2) ** 0.5
        ll = ((g[0][0] - g[1][0])**2 + (g[0][1] - g[1][1]) ** 2) ** 0.5
        
        vec1 = [(g[1][0] - g[0][0]) / ll, (g[1][1] - g[0][1]) / ll]
        vec2 = [(g[0][0] - g[1][0]) / ll, (g[0][1] - g[1][1]) / ll]
        
        c1 = [vec1[0] * l1 + g[0][0], vec1[1] * l1 + g[0][1]]
        c2 = [vec2[0] * l2 + g[1][0], vec2[1] * l2 + g[1][1]]
        
        r1 = ((b[0] - c1[0]) ** 2 + (b[1] - c1[1]) ** 2) ** 0.5
        r2 = ((b[0] - c2[0]) ** 2 + (b[1] - c2[1]) ** 2) ** 0.5
        
        a1 = 0.5 * abs((g[0][0] * b[1] + b[0] * c1[1] + c1[0] * g[0][1]) - (g[0][0] * c1[1] + b[0] * g[0][1] + c1[0] * b[1]))
        a2 = 0.5 * abs((g[1][0] * b[1] + b[0] * c2[1] + c2[0] * g[1][1]) - (g[1][0] * c2[1] + b[0] * g[1][1] + c2[0] * b[1]))
        
        th1 = math.asin((a1 / l1 / l1) * 2)
        if r1 > 2**0.5 * l1:
            th1 = math.pi - th1
        
        th2 = math.asin((a2 / l2 / l2) * 2)
        if r2 > 2**0.5 * l2:
            th2 = math.pi - th2
        
        s1 = l1 * l1 * th1 / 2 - a1
        s2 = l2 * l2 * th2 / 2 - a2
        
        a3 = 0.5 * abs((b[0] * c1[1] + c1[0] * c2[1] + c2[0] * b[1]) - (b[0] * c2[1] + c1[0] * b[1] + c2[0] * c1[1]))
        ans.append(2 * (s1 + s2 + a3 ))
        
    print 'Case #%d:' % c,
    for a in ans:
        print '%.7f' % a,
    print

def main():
    cases = int(raw_input())
    for case in xrange(1, cases + 1):
        solve(case)
    
if __name__ == '__main__':
    main()