import math

if __name__ == '__main__':
    a = input()
    n = len(a)
    a = int(a)
    low = a * a
    up = (a + 1) * (a + 1)
    ans = low
    b = low
    div = 100
    while True:
        add = div - b % div
        if add != div:
            b += add
        if b < up:
            ans = b
        else:
            break
        div *= 100
    while ans % 100 == 0:
        ans //= 100
    print(ans)