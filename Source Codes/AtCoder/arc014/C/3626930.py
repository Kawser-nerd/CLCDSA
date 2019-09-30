N = int(input())
S = input()

beam_width = 3*10**4
next_set = {""}

for c in S:
    a = sorted(next_set, key=len)[:beam_width]
    next_set = set()
    add = next_set.add
    if a[0] == "":
        add(c)
        a = a[1:]

    for s in a:
        add(c+s if c != s[0] else s[1:])
        add(s+c if c != s[-1] else s[:-1])

ss = sorted(next_set, key=len)
print(len(ss[0]))