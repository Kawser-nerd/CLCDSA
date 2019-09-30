s = input().rstrip()
t = input().rstrip()

pushable = [1] * (len(s) - len(t) + 1) 
for i in range(len(s) - len(t) + 1):
    for j in range(len(t)):
        if s[i+j] != t[j] and s[i+j] != "?":
            pushable[i] = 0
            break

if 1 not in pushable:
    print("UNRESTORABLE")
    exit()

ans = []
for i, p in enumerate(pushable):
    cand = s
    if p:
        for j in range(len(t)):
            cand = cand[:i+j] + t[j] + cand[i+j+1:]
        for j in range(len(s)):
            if cand[j] == "?":
                cand = cand[:j] + "a" + cand[j+1:]
        ans.append(cand)

print(sorted(ans)[0])