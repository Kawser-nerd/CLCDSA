S = list(input())
T = list(input())
ans = 0
for i in range(len(S)):
  S.insert(0,S[-1])
  del S[-1]
  if S == T:
    ans += 1
print("Yes" if ans != 0 else "No")