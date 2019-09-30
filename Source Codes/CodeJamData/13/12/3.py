f = open('large.txt')
t = int(f.readline())
for T in xrange(1,t+1):
    E, R, n = (int(x) for x in f.readline().split())
    bound = [0] * (n+2)

    v = [0]+[int(x) for x in f.readline().split()]
    next =[0] * (n+2)
    stack = []

    for i in xrange(1,n+1):
        while len(stack)>0 and v[stack[-1]]<v[i]:
            next[stack.pop()] = i
        stack.append(i)

    while len(stack)>0: next[stack.pop()] = E+n

    for i in xrange(n-1,0,-1):
        bound[i] = max(0, E-R*(next[i]-i))

    ans = 0
    energy = E
    for i in xrange(1,n+1):
        if energy>bound[i]:
            ans += (energy-bound[i])*v[i]
            energy = bound[i]
        energy = min(E, energy+R)

    print 'Case #%d: %d'%(T,ans)