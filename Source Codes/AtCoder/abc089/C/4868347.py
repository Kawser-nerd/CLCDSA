import itertools
n = int(input())
M = []
A = []
R = []
C = []
H = []
for i in range(n):
    s = str(input())
    if s[0] == "M":
        M.append(s)
    elif s[0] == "A":
        A.append(s)
    elif s[0] == "R":
        R.append(s)
    elif s[0] == "C":
        C.append(s)
    elif s[0] == "H":
        H.append(s)
L = []
if len(M) > 0:
    L.append(M)
if len(A) > 0:
    L.append(A)
if len(R) > 0:
    L.append(R)
if len(C) > 0:
    L.append(C)
if len(H) > 0:
    L.append(H)
ans = 0
for i in itertools.combinations(L, 3):
    #print(i)
    ans += len(i[0])*len(i[1])*len(i[2])

print(ans)