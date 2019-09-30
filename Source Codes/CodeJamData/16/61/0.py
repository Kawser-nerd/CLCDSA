if 1:
    from sys import *
    from functools import *
    from collections import *
    from itertools import *
    from functools import *
    from heapq import *
    xr = xrange

    def print_args(*args, **kwargs):
        return ','.join(value for value in [','.join(map(repr, args)),','.join("%s=%s" % (k, repr(v)) for k, v in kwargs.items())] if value)

    def print_result(before=False, after=True):
        def fc(func):
            @wraps(func)
            def f(*args, **kwargs):
                if before:
                    print "%s(%s)"      % (func.__name__, print_args(*args, **kwargs))
                r = func(*args, **kwargs)
                if after:
                    print "%s(%s) = %s" % (func.__name__, print_args(*args, **kwargs), r)
                return r
            return f
        return fc

    def memoize(function):
        memo = {}
        @wraps(function)
        def f(*args):
            key = args
            if key not in memo:
                memo[key] = function(*args)
                if not (len(memo) & 32767):
                    print >>stderr, "memo", function.__name__, len(memo)
            return memo[key]
        f.memo = memo
        return f

    def line():
        return raw_input().strip()

    def parts(f=int):
        return map(f, line().split())

    def qparts(f=int):
        data = line().split()
        return data[0], map(f, data[1:])


def process(s):
    s += '$'
    n = len(s)
    indices = [None]*len(s)
    child = [[] for i in xrange(len(s))]
    opens = []
    valid = 0
    for i in xrange(n):
        if s[i] == '(':
            opens.append(i)
        elif s[i] == ')':
            j = opens.pop()
            indices[i] = j
            indices[j] = i
        elif s[i] == '|':
            indices[i] = opens[-1]
            child[indices[i]].append(i)
        elif s[i] == '*':
            pass
        else:
            valid |= 1 << i

    def is_accept(mask):
        return int((mask & (1 << n-1)) != 0)

    # print 's is'
    # print s

    def print_state(state):
        t = [s[i] if state & (1<<i) else '.' for i in xrange(n)]
        return ''.join(t)

    @memoize
    def cleanse(mask):
        v = 0
        for i in xrange(n):
            if mask & (1<<i):
                v |= _cleanse(i)
        return v

    @memoize
    def _cleanse(i):
        oi = i
        total = 0
        stack = [i]
        while stack:
            i = stack.pop()
            # print oi, stack, i
            if total & (1 << i): continue
            total |= 1 << i
            if s[i] == '(':
                j = indices[i]
                if s[j+1] == '*':
                    stack.append(i+1)
                    stack.append(j+2)
                else:
                    stack.append(i+1)
                    for j in child[i]:
                        stack.append(j+1)
            elif s[i] == ')':
                j = indices[i]
                if s[i+1] == '*':
                    stack.append(j)
                else:
                    stack.append(i+1)
            elif s[i] == '|':
                stack.append(indices[indices[i]]+1)

        # print 'done'
        # print '_cleanse', oi, print_state(total & valid)
        return total & valid

    @memoize
    def proceed(state, d):
        assert 0 <= d <= 9
        v = 0
        for i in xrange(n):
            if state & (1<<i):
                assert s[i] in '0123456789$'
                if s[i] == str(d):
                    v |= 1 << i+1
        # print 'proceed', print_state(state), d, print_state(cleanse(v))
        return cleanse(v)
    # print 'here'
    initial = cleanse(1<<0)
    # print 'here'

    def count(n):
        n = str(n)
        total = _count(n, 1, initial)
        for i in xrange(len(n)):
            total += _count('9'*i, 1, initial)
        return total

    @memoize
    def _count(n, start, state):
        # print 'hey', n
        if not n:
            # print 'counting', print_state(state), n, is_accept(state)
            return is_accept(state)
        d = int(n[0])
        rest = n[1:]
        rest9 = '9'*len(rest)
        ans = 0
        for i in xrange(start,d):
            ans += _count(rest9, 0, proceed(state, i))
        if start <= d:
           ans += _count(rest, 0, proceed(state, d))
        # print 'counting', print_state(state), n, ans
        return ans

    return count






for cas in xrange(1,1+input()):
    ans = 0
    a, b = parts()
    r = process(line())
    ans = r(b) - r(a-1)
    
    #print "Case #%s:" % cas
    print "Case #%s: %s" % (cas, ans)
