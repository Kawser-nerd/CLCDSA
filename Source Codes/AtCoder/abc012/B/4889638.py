def calc(n):
    if n < 10:
        return "0" + str(n)
    else:
        return str(n)

n = int(input())
h = n // 3600
n = n - h * 3600
m = n // 60
n = n - m * 60
s = n
ans = calc(h) + ":" + calc(m) + ":" + calc(s)
print(ans)