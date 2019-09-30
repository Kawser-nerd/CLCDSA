# Marius Damarackas (m.damarackas@gmail.com)
# Google CodeJam, Round 2, 2009-09-26

n, k, prices, M = None, None, None, None

def overlap(prices, i, j):
    return not (all(a < b for a, b in zip(prices[i], prices[j]))
                or all(a > b for a, b in zip(prices[i], prices[j])))

best = 100000

color = None
colors_used = None

def search(v):
    global best, color, colors_used
    if v == n:
        best = min([best, colors_used])
    else:
        nc = set()
        for i in range(n):
            if i != v and M[i][v] and color[i] != None:
                nc.add(color[i])
        for c in range(colors_used):
            if c not in nc:
                color[v] = c
                search(v + 1)
                color[v] = None
        if colors_used + 1 >= best:
            return
        colors_used += 1
        color[v] = colors_used - 1
        search(v + 1)
        color[v] = None
        colors_used -= 1
                

def solve():
    global n, k, prices, M, best, color, colors_used
    best = 100000
    color = [None for i in range(n)]
    colors_used = 0
    M = [[None for i in range(n)] for j in range(n)]
    for i in range(n):
        for j in range(n):
            M[i][j] = overlap(prices, i, j)
    search(0)
    return best

def main():
    global n, k, prices
    file = open("input.in")
    tests = int(file.readline())
    for case in range(1, tests + 1):
        n, k = [int(x) for x in file.readline().split()]
        prices = []
        for i in range(n):
            prices.append([int(x) for x in file.readline().split()])
        print("Case #", case, ": ", solve(), sep="")

if __name__ == "__main__":
    main()
