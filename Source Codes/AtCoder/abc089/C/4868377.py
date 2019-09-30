import itertools
n = int(input())
L = [[]for i in range(5)]
for i in range(n):
    s = str(input())
    if s[0] == "M":
        L[0].append(s)
    elif s[0] == "A":
        L[1].append(s)
    elif s[0] == "R":
        L[2].append(s)
    elif s[0] == "C":
        L[3].append(s)
    elif s[0] == "H":
        L[4].append(s)
L = [ i for i in L if len(i) > 0]
ans = 0
for i in itertools.combinations(L, 3):
    ans += len(i[0])*len(i[1])*len(i[2])
print(ans)