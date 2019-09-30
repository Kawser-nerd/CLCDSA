#!/usr/bin/env python3

def split(n):
    return n//2, (n-1)//2

def merge(a, n1, n2, b, m1, m2):
    if n1 == m1:
        return a+a+b, n1, b, m2
    elif n2 == m2:
        return a, n1, a+b+b, m2
    else:
        raise Exception("Can't reduce {}".format((n1, n2, m1, m2)))

def solve(a, n, b, m, k):
    if k <= a:
        return split(n)
    elif k <= a+b:
        return split(m)
    else:
        #solve(*merge(a, *split(n), b, *split(m)), k-a-b)
        # Python pre-3.5 doesn't have extended unpacking
        # see https://www.python.org/dev/peps/pep-0448/
        def t(*args):
            return tuple(args)
        return solve(*(merge(*(t(a) + split(n) + t(b) + split(m))) + t(k-a-b)))

def main():
    t = int(input())
    for ti in range(t):
        n, k = map(int, input().split(" "))
        print("Case #{}: {}".format(ti+1, ' '.join(map(str, sorted(solve(1, n, 0, n-1, k), reverse=True)))))

if __name__ == '__main__':
    main()
