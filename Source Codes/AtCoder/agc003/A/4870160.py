S = input()

s = set(S[:])
ans = s == set(["N", "W", "S", "E"]) or s == set(["N", "S"]) or s == set(["W", "E"])

print("Yes" if ans else "No")