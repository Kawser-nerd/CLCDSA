n, m, l = map(int, input().split())
p, q, r = map(int, input().split())
cou = 0

def calc(a, b, c):
    return (n//a) * (m//b) * (l//c)

cou = max(cou, calc(p, q, r))
cou = max(cou, calc(p, r, q))
cou = max(cou, calc(q, p, r))
cou = max(cou, calc(q, r, p))
cou = max(cou, calc(r, p, q))
cou = max(cou, calc(r, q, p))

print(cou)