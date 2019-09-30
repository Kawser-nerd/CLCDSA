a = list(input())
b = list(input())
c = list(input())
d = "a"
win = "no"
while (win == "no"):
    if d == "a":
        d = a[0]
        a = a[1:]
    elif d == "b":
        d = b[0]
        b = b[1:]
    elif d == "c":
        d = c[0]
        c = c[1:]
    if ((d == "a") & (len(a) == 0)):
        win = "A"
    elif ((d == "b") & (len(b) == 0)):
        win = "B"
    elif ((d == "c") & (len(c) == 0)):
        win = "C"
print(win)