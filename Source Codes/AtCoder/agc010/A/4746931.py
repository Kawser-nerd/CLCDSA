N = int(input())
A = [int(i)%2 for i in input().split()]

if A.count(0) == 0 and A.count(1)==1:
  print("YES")
elif A.count(1)%2==0:
  print("YES")
else:
  print("NO")