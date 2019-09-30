s = list(input())
t = ""
for s_ in s:

    if s_ != "B":
        t += s_
    else:
        t = t[:-1]
print(t)