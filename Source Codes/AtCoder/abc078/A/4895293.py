list = [ord(i) for i in input().split()]
if list[0] == list[1]:
  print("=")
elif list[0] < list[1]:
  print("<")
else:
  print(">")