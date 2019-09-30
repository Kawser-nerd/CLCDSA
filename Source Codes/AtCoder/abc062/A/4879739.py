[x,y] = list(map(int, input().split()))
s1 = [1,3,5,7,8,10,12]
s2 = [4,6,9,11]
if x == 2:
  print("No")
elif x in s1 and y in s1:
  print("Yes")
elif x in s2 and y in s2:
  print("Yes")
else:
  print("No")