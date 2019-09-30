N = int(input())
s = input()
t = input()

common = 0
for i in range(min(len(s) + 1, len(t) + 1)):
    if s[-i:] == t[:i]:
        common = i
ans = len(s + t[common:])

print(ans)