#coding:UTF-8
work = input().split(" ")
r = int(work[0])
b = int(work[1])
g = int(work[2])
num = r*100 + b*10 +g
if(num % 4 == 0):
  print("YES")
else:
  print("NO")