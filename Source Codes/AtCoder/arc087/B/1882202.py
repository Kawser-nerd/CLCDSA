def f(m, s, g):
    for i in m:
        if s > g:
            s -= i
        else:
            s += i
    return s == g
s = input()
x, y = map(int, input().split())
m = list(map(len, s.split('T')))
if (f(sorted(m[::2][1::])[::-1], m[0], x)
        and f(sorted(m[1::2])[::-1], 0, y)):
    print('Yes')
else:
    print('No')