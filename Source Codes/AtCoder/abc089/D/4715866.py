def solve(string):
    h, w, d, *a = map(int, string.split())
    n = h * w
    a, q, lr = a[:n], a[n], a[n + 1:]
    index = [0] * n
    for i, _a in enumerate(a):
        index[_a - 1] = i
    diff = [0] * d + [
        abs(i0 // w - i1 // w) + abs(i0 % w - i1 % w) for i0, i1 in zip(index, index[d:])
    ]
    for i in range(n):
        if i >= d:
            diff[i] += diff[i - d]
    return "\n".join([str(diff[r - 1] - diff[l - 1]) for l, r in zip(lr[::2], lr[1::2])])


if __name__ == '__main__':
    n, m, d = map(int, input().split())
    ins = '{} {} {}\n'.format(n, m, d) + '\n'.join([input() for _ in range(n)])
    n = int(input())
    print(solve(ins + '\n{}\n'.format(n) + '\n'.join([input() for _ in range(n)])))