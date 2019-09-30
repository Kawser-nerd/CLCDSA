A, B, C = list(map(int, input().split()))

if A == B and B == C:
  if A % 2 == 1 or B % 2 == 1 or C % 2 == 1:
    print("0")
  else:
    print("-1")
  exit()

for i in range(100000):
  if A % 2 == 1 or B % 2 == 1 or C % 2 == 1:
    Ans = i
    break
  a = A // 2
  b = B // 2
  c = C // 2
  A = b + c
  B = c + a
  C = a + b

print(Ans)