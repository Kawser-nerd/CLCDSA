N = input()
S = 0
for n in N:
  S += int(n)
N = int(N)
print("Yes" if N%S == 0 else "No")