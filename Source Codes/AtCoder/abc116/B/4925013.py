def f(n):
    if n % 2 == 0:
        return n / 2
    else:
        return (n*3) + 1

s = int(input())
l = [s]
m = 1

while True:
    num = f(l[m-1])
    if num not in l:
        l.append(num)
        m += 1
    else:
        print(m + 1)
        break