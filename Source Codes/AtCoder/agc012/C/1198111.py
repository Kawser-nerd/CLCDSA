n = int(input()) + 1

k = 50
while ~n >> k & 1:
    k -= 1
k -= 1

a = []
b = []
now = 1
while k >= 0:
    a = a + [now]
    b = b + [now]
    now += 1

    if n >> k & 1:
        a = a + [now]
        b = [now] + b
        now += 1

    k -= 1

print(len(a + b))
print(*(a + b))