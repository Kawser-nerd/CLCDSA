S = input()
T = input()
for i in reversed(range(len(S) - len(T) + 1)):
    frag = True
    for j in range(len(T)):
        if S[i + j] == T[j] or S[i + j] == "?":
            continue
        else:
            frag = False
            break
    if frag:
        ans = S[:i] + T
        if i + len(T) < len(S):
            ans += S[i + len(T):]
        ans = ans.replace("?", "a")
        print(ans)
        exit()
print("UNRESTORABLE")