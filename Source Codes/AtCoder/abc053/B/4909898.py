S = input()
for i in range(len(S)):
    if S[i] == "A":
        start = i
        break
for i in reversed(range(len(S))):
    if S[i] == "Z":
        last = i
        break
print(last-start+1)