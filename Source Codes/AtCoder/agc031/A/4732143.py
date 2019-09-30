n = int(input())
s = input()
s_set = set(s)
S = []
for i in s_set:
    S.append(s.count(i))

ans = 1
for i in S:
    ans *= i + 1
    ans %= 10 ** 9 + 7

print(ans - 1)