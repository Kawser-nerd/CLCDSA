mod = 10**9 + 7

N = int(input())
S = input()

dic = {}
for s in "abcdefghijklmnopqrstuvwxyz":
    dic[s] = 0

for s in S:
    dic[s] += 1

ans = 1
for v in dic.values():
    ans *= v + 1
print((ans - 1) % mod)