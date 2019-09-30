N = input()
S=0
for n in N:
  S += int(n)
N = int(N)
if N%S==0:
  print("Yes")
else:
  print("No")