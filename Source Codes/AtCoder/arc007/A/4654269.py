X = input()
S = input()
newS = ''
for c in S:
    if c != X:
        newS += c
print(newS)