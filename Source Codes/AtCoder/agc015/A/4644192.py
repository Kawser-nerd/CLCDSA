N, A, B = list(map(int, input().split()))

if N == 1:
  if A != B:
    print(0)
  else:
    print(1)
  exit()
if A > B:
  print(0)
  exit()

N -= 2
Ans = (B - A) * N + 1
print(Ans)