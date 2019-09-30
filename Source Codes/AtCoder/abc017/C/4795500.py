n, m = map(int, input().split())
imosu = [0] * (m + 1)
sum_val = 0
for i in range(n):
    l, r, s = map(int, input().split())
    imosu[l - 1] += s
    imosu[r] -= s
    sum_val += s
for i in range(m+1):
    if i > 0:
        imosu[i] += imosu[i - 1]
print(sum_val - min(imosu[:-1]))