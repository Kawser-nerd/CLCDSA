s = input()
n = len(s)
k = 0
for i in range(n//2):
  if s[i] != s[n-1-i]:
    k += 1
if k == 0:
  a = 25*(n-n%2)
elif k == 1:
  a = 25*n-2
else:
  a = 25*n
print(a)