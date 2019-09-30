n = input()
if n in "235":
  print("Prime")
elif n[-1] in "245680" or int(n)%3 == 0 or n == "1":
  print("Not Prime")
else:
  print("Prime")