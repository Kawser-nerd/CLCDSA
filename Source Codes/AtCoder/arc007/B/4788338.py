def main():
    n, m = map(int, input().split())
    discs = [i for i in range(n + 1)]
    current = 0

    for _ in range(m):
        d = int(input())
        discs[current] = discs[d]
        discs[d] = 0
        current = d
    
    cases = [None for _ in range(n + 1)]
    for i in range(n + 1):
        cases[discs[i]] = i
    
    for i in range(1, n + 1):
        print(cases[i])

main()