S = input()
lst = ["dreamer", "dream", "eraser", "erase"]
lst = [ "".join(list(reversed(k))) for k in lst]
S = "".join(list(reversed(S)))

i  = 0
while i < len(S):
    found = False
    for k in lst:
        try:
            if S[i:].index(k) == 0:
                found = True
                i += len(k)
                break
        except:
            continue

    if not found:
        print("NO")
        exit(0)
print("YES")