N = int(input())

digit = len(str(N))
count = 0
for i in range(1, digit + 1):
    count += (N + 1) // (10**i) * (10**(i - 1))
    rest = (N + 1) % (10**i)
    if 10**(i - 1) < rest:
        count += min(10**(i - 1), rest - 10**(i - 1))

print(count)