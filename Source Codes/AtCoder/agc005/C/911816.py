input()
a = list(map(int, input().split()))

def resolve(a):
    if a == [1, 1]:
        return True

    if a.count(1) >= 2:
        return False

    max_num = max(a)
    min_num = min(a)

    if a.count(max_num) < 2:
        return False

    if max_num / 2 > min_num:
        return False

    if max_num & 1:
        # ??
        for i in range(max_num // 2 + 1, max_num):
            if i not in a: return False

        if a.count(min_num) > 2:
            return False
    else:
        # ??
        for i in range(max_num // 2, max_num):
            if i not in a: return False

        if a.count(min_num) > 1:
            return False
    return True

print("Possible" if resolve(a) else "Impossible")