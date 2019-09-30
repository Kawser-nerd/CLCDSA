S = input()
T = input()
for i in range(len(S)):
    if S[i] == T[0]:
        new_s = S[i:] + S[:i]
        if new_s == T:
            print("Yes")
            exit()
print("No")