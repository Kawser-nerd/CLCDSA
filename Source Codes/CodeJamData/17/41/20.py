from copy import copy
def task():
    n, p = map(int, input().split())
    groups = map(int, input().split())
    mods = [0] * p
    for group in groups:
        mods[group % p] += 1
    if p == 2:
        return mods[0] + (mods[1] + 1) // 2
    if p == 3:
        m = min(mods[1], mods[2])
        mods[1] -= m
        mods[2] -= m
        return mods[0] + m + (mods[1] + 2) // 3 + (mods[2] + 2) // 3
    if p == 4:
        result = mods[0]
        mods[0] = 0
        m = min(mods[1], mods[3])
        mods[1] -= m
        mods[3] -= m
        result += m
        mods1 = copy(mods)
        result1 = result + (mods1[2] // 2)
        mods1[2] %= 2
        k = min((mods1[3] + mods1[1]) // 2,  mods1[2])
        result1 += k
        mods1[3] = max(0, mods1[3] -k*2)
        mods1[1] = max(0, mods1[1] -k*2)
        mods1[2] -= k
        result1 += (mods1[3] + mods1[1]) // 4
        mods1[3] %= 4
        mods1[1] %= 4
        if sum(mods1) > 0:
            result1 += 1

        mods2 = copy(mods)
        result2 = result
        k = min((mods2[3] + mods2[1]) // 2,  mods2[2])
        result2 += k
        mods2[3] = max(0, mods2[3] -k*2)
        mods2[1] = max(0, mods2[1] -k*2)
        mods2[2] -= k
        result2 += (mods2[3] + mods2[1]) // 4
        mods2[3] %= 4
        mods2[1] %= 4
        result2 += mods2[2] // 2
        mods2[2] %= 2
        if sum(mods2) > 0:
            result2 += 1

        return max(result1, result2)

t = int(input())
for i in range(t):
    print("Case #{}: {}".format(i+1, task()))
