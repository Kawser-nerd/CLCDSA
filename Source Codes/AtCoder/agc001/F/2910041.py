def invert(p, q):
    for i, pi in enumerate(p): q[pi] = i

def sort_insertion(k, data, first, last):
    length = last - first
    if length <= 2:
        if length == 2 and data[first] - data[first + 1] >= k:
            data[first], data[first + 1] = data[first + 1], data[first]
        return
    for i in range(first + 1, last):
        v = data[i]
        for t in range(i - 1, first - 1, -1):
            if data[t] - v < k:
                t += 1
                break
        data[t + 1:i + 1] = data[t:i]
        data[t] = v

def sort_merge(k, data, first, last):
    if last - first < 10:
        sort_insertion(k, data, first, last)
        return

    middle = (first + last) // 2
    sort_merge(k, data, first, middle)
    sort_merge(k, data, middle, last)
    bounds = data[first:middle]
    for i in range(len(bounds) - 2, -1, -1):
        bounds[i] = min(bounds[i + 1], bounds[i])
    tmp = data[first:middle]

    first_len = middle - first
    head1 = 0
    head2 = middle
    for ohead in range(first, last):
        if head1 == first_len or head2 == last:
            data[ohead:ohead + first_len - head1] = tmp[head1:first_len]
            return
        elif bounds[head1] - data[head2] >= k:
            data[ohead] = data[head2]
            head2 += 1
        else:
            data[ohead] = tmp[head1]
            head1 += 1

n, k = (int(s) for s in input().split(' '))
p = [int(s) - 1 for s in input().split(' ')]

q = list(p)
invert(p, q)
sort_merge(k, q, 0, n)
invert(q, p)

for pi in p: print(pi + 1)