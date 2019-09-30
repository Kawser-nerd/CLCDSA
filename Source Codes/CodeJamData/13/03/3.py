def digits(x):
    r = []
    while x:
        r.append(x % 10)
        x //= 10
    return list(reversed(r))

def is_pal(x):
    d = digits(x)
    for i in range(len(d) // 2):
        if d[i] != d[len(d) - i - 1]:
            return False
    return True

def palindromes():
    l = 1
    half = 1
    while True:
        d = digits(half)
        c = half
        if l % 2:
            d = d[:-1]
        for i in reversed(d):
            c = c * 10 + i
        half += 1
        if half == 10 ** ((l + 1) // 2):
            l += 1
            half = 10 ** ((l - 1) // 2)
        yield c

def from_digits(d):
    x = 0
    for i in d:
        x = 10 * x + i
    return x

def prev(x):
    d = digits(x)
    d = d[1:-1]
    while d and d[0] == 0:
        d = d[1:-1]
    return from_digits(d)

t = []

def find_all(x, l, n0):
    global t
    if x > 99 and n0 and not is_pal(x ** 2):
        return
    if n0 and is_pal(x ** 2) and x ** 2 <= 10**100:
        t.append(x ** 2)
    if l > 50:
        return
    find_all(2 * 10 ** (l + 1) + 10 * x + 2, l + 2, True)
    find_all(10 ** (l + 1) + 10 * x + 1, l + 2, True)
    find_all(10 * x, l + 2, False)

find_all(0, 0, False)
find_all(0, 1, False)
for i in range(1, 10):
    find_all(i, 1, True)

t.sort()

n_cases = int(input())

import bisect

for i in range(1, n_cases + 1):
    a, b = map(int, input().split())
    res = bisect.bisect_right(t, b) - bisect.bisect_left(t, a)
    print('Case #{}: {}'.format(i, res))
    
#t2 = []
#
#for i in palindromes():
#    if is_pal(i ** 2):
#        t2.append(i)
#        if i > 10**11:
#            break
#
#for i in range(1, 10**6):
#    if is_pal(i) and is_pal(i ** 2):
#        t2.append(i)
#
#print(t[:len(t2)])
#print(t2)
#assert t[:len(t2)] == t2
