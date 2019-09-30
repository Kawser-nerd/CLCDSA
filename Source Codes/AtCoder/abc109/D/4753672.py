def d_make_them_even(H, W, A):
    from itertools import product
    grid = [row for row in A]
    ans_tmp = []
    for h, w in product(range(H), range(W)):
        if grid[h][w] % 2 == 1:
            # ???1????????????????
            for dh, dw in zip((0, 1), (1, 0)):
                if 0 <= h + dh < H and 0 <= w + dw < W:
                    grid[h + dh][w + dw] += 1
                    grid[h][w] -= 1
                    ans_tmp.append('{} {} {} {}'.format(h + 1, w + 1, h + dh + 1, w + dw + 1))
                    break
    return str(len(ans_tmp)) + '\n' + '\n'.join(ans_tmp)

H, W = [int(i) for i in input().split()]
A = [[int(i) for i in input().split()] for j in range(H)]
print(d_make_them_even(H, W, A))