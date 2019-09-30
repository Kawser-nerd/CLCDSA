cnt = [0] * 26
n = int(input())
s = input()
for c in s:
    cnt[ord(c) - ord('a')] += 1
res = 1
for i in cnt:
    res *= i + 1
print((res - 1) % (10 ** 9 + 7))