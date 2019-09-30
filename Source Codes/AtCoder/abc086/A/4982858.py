#coding:UTF-8
work = input().split(" ")
a = work[0]
b = work[1]
c = int(a) * int(b)
if( c%2 == 0):
  print("Even")
else:
  print("Odd")