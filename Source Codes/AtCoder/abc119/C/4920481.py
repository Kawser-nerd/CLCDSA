def main():
    n, a, b, c = map(int, input().split())
    l = [int(input()) for _ in range(n)]

    print(solve(a, b, c, l))

def solve(a, b, c, l):
    m = float('inf')
    for x in range(1, 4 ** len(l)):
        m = min(m, eval_cost(x, a, b, c, l))
    return m

def eval_cost(x, a, b, c, l):
    cnt = [0, 0, 0]
    y = [0, 0, 0]

    for i in range(len(l)):
        n = (x >> (i * 2)) & 0x03
        if n < 3:
            cnt[n] += 1
            y[n] += l[i]

    if cnt.count(0) != 0:
        return float('inf')
    
    return (sum(cnt) - 3) * 10 + abs(y[0] - a) + abs(y[1] - b) + abs(y[2] - c)

main()