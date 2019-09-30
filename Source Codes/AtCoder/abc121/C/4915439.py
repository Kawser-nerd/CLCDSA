n,m = map(int,input().split())
src = []
for i in range(n):
    a,b = map(int,input().split())
    src.append([a,b])

src.sort(key = lambda x:-x[0])
sum_pay = 0
while 1:
    a,b = src.pop()
    if m > b:
        sum_pay += a*b
        m -= b
    else:
        sum_pay += a*m
        break
print(sum_pay)