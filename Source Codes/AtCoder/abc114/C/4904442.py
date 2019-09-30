import itertools
ans = 0
nums = []
N = int(input())
for k in range(1, 10):
    s = itertools.product(['3', '5', '7'], repeat = k)
    for seq in s:
        num = ''.join(seq)
        nums.append(num)
for num in nums:
    if '3' in num and '5' in num and '7' in num and int(num) <= N:
        ans += 1
print(ans)