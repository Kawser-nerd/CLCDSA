import sys

S = [i for i in input()]
if S[0] != "A":
    print("WA")
    sys.exit()
else:
    S[0] = 'a'

ct = 0
for i in range(len(S[2:-1])):
    if S[i+2] == "C":
        S[i+2] = "c"
        ct += 1
    if ct > 1:
        print("WA")
        sys.exit()
if ct != 1:
    print("WA")
    sys.exit()

for i in S:
    if "a" <= i <= "z":
        pass
    else:
        print("WA")
        sys.exit()

print("AC")