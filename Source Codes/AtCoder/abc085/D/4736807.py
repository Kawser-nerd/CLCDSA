from math import ceil


def solve(string):
    n, h, * ab = map(int, string.split())
    max_a = max(ab[::2])
    cnt = 0
    b = sorted([b for b in ab[1::2] if b > max_a], reverse=True)
    if sum(b) < h:
        cnt = len(b) + ceil((h-sum(b)) / max_a)
    else:
        for _b in b:
            cnt += 1
            h -= _b
            if h <= 0:
                break
    return str(cnt)


if __name__ == '__main__':
    n, m = map(int, input().split())
    print(solve('{} {}\n'.format(n, m)+'\n'.join([input() for _ in range(n)])))