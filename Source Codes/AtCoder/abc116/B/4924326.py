def COL(n):
  if n%2==0:
    return int(n/2)
  else:
    return 3*n+1

s=int(input())
List=[s]
s=COL(s)
while s not in List:
  List.append(s)
  s=COL(s)
print(len(List)+1)