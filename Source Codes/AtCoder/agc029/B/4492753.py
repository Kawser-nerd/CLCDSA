import collections

N = int(input())
A = collections.deque(sorted(map(int,input().split())))


def func1(a, r, rnext):
    p = a.popleft()
    q = a.pop()
    ans = 0
    a1 = collections.deque()
    while True:
        if p + q == r:
            ans += 1
            try:
                p = a.popleft()
            except:
                break
            try:
                q = a.pop()
            except:
                if p < rnext:
                    a1.append(p)
                break
        elif p + q > r:
            try:
                q = a.pop()
            except:
                if p < rnext:
                    a1.append(p)
                break
        else:
            a1.append(p)
            try:
                p = a.popleft()
            except:
                if q < rnext:
                    a1.append(q)
                break
    return ans, a1


if N == 1:
    print(0)
    exit(0)
t = int.bit_length(A[-1] + A[-2])
r = 2 ** t
rnext = 2 ** (t - 1)
anser = 0
a = A

while True:
    ans, a1 = func1(a, r, rnext)
    anser += ans
    if len(a1) < 2:
        break
    a = a1
    t -= 1
    r = rnext
    rnext = 2 ** (t - 1)

print(anser)