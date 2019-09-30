II = lambda: int(raw_input())
for t in range(1, II() + 1):
    print 'Case #%d:' % t,
    
    s = raw_input().strip()
    n = int(s[::-1].replace('+','0').replace('-','1'), 2)
    a = 0
    while n:
        a += n & 3 in {1, 2}
        n >>= 1
    print a
