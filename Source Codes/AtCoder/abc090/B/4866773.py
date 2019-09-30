ans = 0
A, B  = map(int, input().split())

for i in range(A, B+1):
  if str(i)[0] == str(i)[-1] and str(i)[1] == str(i)[-2]:
    ans += 1

print(ans)