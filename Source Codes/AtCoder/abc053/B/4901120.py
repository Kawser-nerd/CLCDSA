s = input()
index = []
for i, c in enumerate(s):
    if c == "A":
        index.append(i)
        break

for i, c in enumerate(reversed(s)):
    if c == "Z":
        index.append(len(s)-i)
        break

count = len(s[index[0]:index[1]])
print(count)