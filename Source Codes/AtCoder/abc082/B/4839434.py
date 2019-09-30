s = input()
t = input()

s = sorted(s)
t = sorted(t, reverse=True)
sl = "".join(s)
tl = "".join(t)

if sl < tl:
    print("Yes")
else:
    print("No")