from collections import defaultdict

N = int(input())
src = list(map(int,input().split()))

dic = defaultdict(lambda:(N,0))
for i,a in enumerate(src):
    m,n = dic[a]
    dic[a] = (min(m,i), n+1)
order = sorted(list(dic.items()))

hist = [0] * N
while True:
    a1, (m1, n1) = order.pop()
    if not order:
        hist[m1] += n1 * a1
        break
    a2, (m2, n2) = order[-1]
    hist[m1] += n1 * (a1-a2)
    order[-1] = (a2, (min(m1,m2), n1+n2))

print(*hist, sep='\n')