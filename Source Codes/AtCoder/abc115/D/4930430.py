from functools import lru_cache

n, x = map(int, input().split())
sizes = [1]
for i in range(50):
    sizes.append(sizes[-1] * 2 + 3)


@lru_cache(maxsize=None)
def count_patti(level, index):
    """
    ??? index ??????????
    :param level:
    :param index:
    :return:
    """
    if level == 0:
        return 1
    if index == 0:
        return 0
    if 1 <= index < (sizes[level] - 1) / 2:
        return count_patti(level - 1, index - 1)
    if index == (sizes[level] - 1) / 2:
        return count_patti(level - 1, sizes[level - 1] - 1) + 1
    if (sizes[level] - 1) / 2 < index < sizes[level] - 1:
        return count_patti(level - 1, sizes[level - 1] - 1) + 1 + \
               count_patti(level - 1, index - (sizes[level] - 1) / 2 - 1)
    else:
        return count_patti(level - 1, sizes[level - 1] - 1) + 1 + \
               count_patti(level - 1, sizes[level - 1] - 1)


print(count_patti(n, x - 1))