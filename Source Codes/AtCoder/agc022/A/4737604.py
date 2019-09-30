S = input()
A = "abcdefghijklmnopqrstuvwxyz"
if len(S)<26:
    for c in A:
        if c not in S:
            print(S+c)
            break
elif S=="zyxwvutsrqponmlkjihgfedcba":
    print(-1)
else:
    for i in range(24,-1,-1):
        for c in A:
            if c not in S[:i] and c>S[i]:
                print(S[:i]+c)
                break
        else:
            continue
        break