def solve(string):
    h, w, d, *a = map(int, string.split())
    a, q, lr = a[:h * w], a[h * w], a[h * w + 1:]
    n = h * w
    index = [0 for _ in range(n)]
    for i, _a in enumerate(a):
        index[_a - 1] = i
    # index = [a.index(i + 1) for i in range(h * w)]
    diff = [0] * d + [
        abs(i0 // w - i1 // w) + abs(i0 % w - i1 % w) for i0, i1 in zip(index, index[d:])
    ]
    costs = []
    for i in range(n):
        if i < d:
            costs.append(diff[i])
        else:
            costs.append(diff[i] + costs[i - d])
    return "\n".join([str(costs[r - 1] - costs[l - 1]) for l, r in zip(lr[::2], lr[1::2])])


if __name__ == '__main__':
    n, m, d = map(int, input().split())
    ins = '{} {} {}\n'.format(n, m, d) + '\n'.join([input() for _ in range(n)])
    n = int(input())
    print(solve(ins + '\n{}\n'.format(n) + '\n'.join([input() for _ in range(n)])))