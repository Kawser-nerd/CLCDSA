n, p = map(int, input().split())
a = list(map(int, input().split()))
odd_count = sum([i % 2 == 1 for i in a])
if p == 0:
    if odd_count == 0:
        print(2**(n-odd_count))
    else:
        print((2**(n-odd_count)) * (2 ** (odd_count - 1)))
else:
    if odd_count == 0:
        print(0)
    else:
        print((2**(n-odd_count)) * (2 ** (odd_count - 1)))