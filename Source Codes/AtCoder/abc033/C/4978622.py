def calc(l):
    if "0" in l:
        return 0
    return 1

s = input().split("+")
t = [int(s_) if "*" not in s_  else calc(s_) for s_ in s]
ans = len(t) - t.count(0)
print(ans)