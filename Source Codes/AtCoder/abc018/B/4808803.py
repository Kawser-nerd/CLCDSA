s = list(input())
for _ in range(int(input())):
    l, r = map(int, input().split())
    ss = "".join(list(reversed(s[l-1:r])))
    s[l-1:r] = ss
print("".join(s))