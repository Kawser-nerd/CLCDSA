input_string = input()
n = int(input_string)
s = sum([int(x) for x in list(input_string)])

if(n % s)== 0 :
  print("Yes")
else :
  print("No")