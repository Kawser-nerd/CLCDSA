def f(n):
    if n%2==0:
        return n/2
    else:
        return 3*n+1

s = int(input())
hist = [s, ]
m = 1
while True:
    elem = f(hist[m-1])
    if elem not in hist:
        hist.append(elem)
        m += 1
    else:
        print(m+1)
        break