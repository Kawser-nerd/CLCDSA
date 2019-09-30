A=[int(input()) for i in range(3)]
s=sorted(A)[::-1]
for i in A:
  print(s.index(i)+1)