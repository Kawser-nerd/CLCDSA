from functools import lru_cache

@lru_cache(maxsize=1000)
def lucas(i):
    if i == 0:
        return 2
    if i == 1:
        return 1
    return lucas(i - 1) + lucas(i - 2)

print(lucas(int(input())))