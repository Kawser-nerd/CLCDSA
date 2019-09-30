s=input()
n=len(s)
l=[True if s[i]==s[-i-1] else False for i in range(n//2)]

if all(l): #kaibun
  print(25*(n-n%2))
elif n//2-sum(l)==1:
  print(25*n-2)
else:
  print(25*n)