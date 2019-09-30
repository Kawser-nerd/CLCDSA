S = [str(_) for _ in input()]
revS = S[::-1]

for i in range(len(S)):
    if S[i] == "*":
        revS[i] = "*"
    elif revS[i] == "*":
        S[i] = "*"

print("YES" if S==revS else "NO")