S = {c:list(input()) for c in "abc"}

s = "a"

while S[s]:
  s = S[s].pop(0)

print(s.upper())