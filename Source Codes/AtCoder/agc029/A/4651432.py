S = input()

ans = 0
white = [0]*len(S)
w = 0

for i in range(len(S)):
  if S[i] == "W":
    white[w] += i
    w += 1
for i in range(len(S)):
  if white[i] > 0:
    ans += white[i]-i
print(ans)