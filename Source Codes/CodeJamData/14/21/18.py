import sys
import math

T = int(sys.stdin.readline())

for i in xrange(T):
        sys.stdout.write('Case #%d: ' % (i+1))
        n = int(sys.stdin.readline())
        strs = []
        flag = False
        for _ in xrange(n):
                line = sys.stdin.readline()
                if flag:
                        continue
                x = []
                now = None
                count = 0
                for ch in line:
                        if ch != now:
                                if now:
                                        x.append((now, count))
                                now = ch
                                count = 1
                        else:
                                count += 1
               # sys.stderr.write('%s\n' % repr(x))
                if strs:
                        if len(strs[0]) != len(x):
                                flag = True
                                continue
                        for i in xrange(len(x)):
                                if strs[0][i][0] != x[i][0]:
                                        flag = True
                                        break
                        if flag:
                                continue
                        strs.append(x)
                else:
                        strs.append(x)


        if flag:
                print 'Fegla Won'
        else:
                tot = 0
                for i in xrange(len(strs[0])):
                        a = []
                        for j in xrange(len(strs)):
                                a.append(strs[j][i][1])
                        a.sort()
                        mid = a[len(a)/2]
                        tot += sum([abs(x-mid) for x in a])
                print tot

                

