s = input()
k = int(input())
plist = []
for i in range(len(s) - k + 1):
    tmp = s[i:i+k]
    if tmp not in plist:
        plist.append(tmp)
print(len(plist))