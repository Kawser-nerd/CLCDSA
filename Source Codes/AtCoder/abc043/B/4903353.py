answer =[]

for letter in input():
  if letter=="1":
    answer.append("1")    
  elif letter=="0":
    answer.append("0")    
  elif letter=="B" and len(answer)>0:
    answer.pop()
    
print("".join(answer))