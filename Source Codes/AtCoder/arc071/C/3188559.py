S = input()
T = input()
def sign(s):
    if len(s)==1:
        return s
    elif s=="AA":
        return "B"
    elif s in ["AB", "BA"]:
        return ""
    elif s=="BB":
        return "A"

def diff(a, b):
    if b=="":
        return a
    elif b==a:
        return ""
    elif a=="":
        if b=="A":
            return "B"
        elif b=="B":
            return "A"
    else:
        return b

a = ""
Sn = [""]
for s in S:
    a = sign(a+s)
    Sn.append(a)
a = ""
Tn = [""]
for t in T:
    a = sign(a+t)
    Tn.append(a)

q = int(input())
for i in range(q):
    a, b, c, d = map(int, input().split())
    if diff(Sn[b], Sn[a-1]) == diff(Tn[d], Tn[c-1]):
        print("YES")
    else:
        print("NO")