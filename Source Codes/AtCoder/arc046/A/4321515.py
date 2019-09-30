def a_repdigit(N):
    """
    N???????(??????)??
    """

    from itertools import repeat
    count, digit = 1, 0
    while True:
        for k in range(1, 10):
            if count == N:
                return ''.join(map(str, repeat(k, digit + 1)))
            count += 1
        digit += 1
    return None

N = int(input())
print(a_repdigit(N))