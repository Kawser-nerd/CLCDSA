BUTTONS = 'ABXY'

def main():
    _ = int(input())
    c = input()
    print(solve(c))

def solve(c):
    m = float('inf')
    for a in shortcuts():
        for b in shortcuts():
            if b <= a:
                continue
            m = min(m, min_step(c, a, b))
    return m

def min_step(c, a, b):
    dp = [0, 1]
    for i in range(len(c) - 1):
        if c[i:i+2] in (a, b):
            dp.append(min(dp[-2] + 1, dp[-1] + 1))
        else:
            dp.append(dp[-1] + 1)
    return dp[-1]

def shortcuts():
    for a in BUTTONS:
        for b in BUTTONS:
            yield a + b
main()