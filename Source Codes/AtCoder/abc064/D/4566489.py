N = int(input())
S = input()

l, r = 0, 0
for s in S:
    if s == "(":
        l += 1
    elif l:
        l -= 1
    else:
        r += 1

print("(" * r + S + ")" * l)