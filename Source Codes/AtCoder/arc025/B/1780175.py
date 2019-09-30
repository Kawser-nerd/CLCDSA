def solve():
    from itertools import product
    H, W = map(int, input().split())
    a = [list(map(int, input().split())) for _ in [0]*H]
    cumsum = [[[0, 0]]*(W+1)] + [[[0, 0] for _ in [0]*(W+1)] for _ in [0]*H]
    for y, l in enumerate(a, start=1):
        cum_b, cum_w = 0, 0
        for x, (v, (up_b, up_w)) in enumerate(zip(l, cumsum[y-1][1:]), start=1):
            if (x+y%2)%2 == 0:
                cum_b += v
            else:
                cum_w += v
            cumsum[y][x] = [up_b+cum_b, up_w+cum_w]

    result = 0
    for width, height in product(range(1, W+1), range(1, H+1)):
        if result >= width*height:
            continue
        for _y, y in zip(range(H+1), range(height, H+1)):
            for (b1, w1), (b2, w2), (b3, w3), (b4, w4) in zip(cumsum[_y], cumsum[_y][width:], cumsum[y], cumsum[y][width:]):
                b = b1 - b2 - b3 + b4
                w = w1 - w2 - w3 + w4
                if b == w:
                    result = width*height

    print(result)


if __name__ == "__main__":
    solve()