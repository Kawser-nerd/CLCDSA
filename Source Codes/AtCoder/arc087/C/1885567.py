from collections import defaultdict


def solve(n, l, nums):
    xor = 0

    if n == 1:
        for i in range(min(nums), l + 1):
            xor ^= i & -i
        return xor

    for i in range(min(nums), l + 1):
        ni = nums[i]
        for k in ni:
            if k ^ 1 not in ni:
                xor ^= i & -i
            nums[i + 1].add(k // 2)
        del nums[i]
    return xor


n, l = map(int, input().split())
nums = defaultdict(set)
for s in (input() for _ in range(n)):
    nums[l - len(s) + 1].add(int(s, 2) + (1 << len(s)))

print('Alice' if solve(n, l, nums) else 'Bob')