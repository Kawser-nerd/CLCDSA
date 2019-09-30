from skynet.math.numbers import digits

def dijkstra_next_perm(iterable) :
    iterable = list(iterable)
    N = len(iterable)
    i = len(iterable) -1

    while iterable[i - 1] >= iterable[i] :
        i -= 1

    j = N

    while iterable[j - 1] <= iterable[i - 1] :
        j -= 1

    iterable[i - 1], iterable[j - 1] = iterable[j - 1], iterable[i - 1]

    i += 1
    j = N

    while i < j :
        iterable[i - 1], iterable[j - 1] = iterable[j - 1], iterable[i - 1]
        i += 1
        j -= 1

    return iterable

def next_number(n) :
    p = str(n)
    try :
        m = int(''.join(dijkstra_next_perm(p)))
    except IndexError :
        return int(''.join(dijkstra_next_perm(p + '0')))
    if m <= n :
        return int(''.join(dijkstra_next_perm(p + '0')))
    return m

with open('B-large.in') as file :
    t = int(file.readline())
    for i in range(t) :
        n = int(file.readline())
        print("Case #{}: {}".format(i + 1, next_number(n)))
