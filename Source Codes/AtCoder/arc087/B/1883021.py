def solve(s, x, y):
    def update(move):
        ncx = set()
        cx = cxy[is_x]
        for x in cx:
            ncx.add(x + move)
            ncx.add(x - move)
        cxy[is_x] = ncx

    spl = map(len, s.split('T'))
    is_x = 1
    cxy = [{next(spl)}, {0}]
    for l in spl:
        update(l)
        is_x ^= 1

    return x in cxy[0] and y in cxy[1]


s = input()
x, y = map(int, input().split())
print('Yes' if solve(s, x, y) else 'No')