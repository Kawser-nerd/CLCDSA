from datetime import date

YEAR = 2012

def main():
    a = []
    n = int(input())
    
    for _ in range(n):
        m, d = map(int, input().split('/'))
        a.append(date(YEAR, m, d))
    
    print(solve(a))

def solve(a):
    s = [0 for _ in range(366)]
    base = date(YEAR, 1, 1)

    for i in range(6, 366, 7):
        s[i] = 1
    for i in range(0, 366, 7):
        s[i] = 1
    
    for h in a:
        d = (h - base).days
        while d < len(s) and s[d] == 1:
            d += 1

        if d < len(s):
            s[d] = 1
    
    return conseq_len(s)

def conseq_len(s):
    m = r = 0
    for x in s:
        if x == 1:
            r += 1
            m = max(m, r)
        else:
            r = 0
    return m

main()