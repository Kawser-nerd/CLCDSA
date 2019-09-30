n=int(input())
list=list(input())
gpa=0
for i in range(n):
  if list[i]=="A":
    gpa+=4
  elif list[i]=="B":
    gpa+=3
  elif list[i]=="C":
    gpa+=2
  elif list[i]=="D":
    gpa+=1
print(gpa/n)