s = input()
moji = ["Mi","Fa","","So","","La","","Si","Do","","Re","","Mi","Fa","","So","","La","","Si","Do","","Re","","Mi"][::-1]
moji2 = ["Mi","Fa","","So","","La","","Si","Do","","Re","","Mi","Fa","","So","","La","","Si"][::-1]
for i in range(11):
  if s[i]=="W" and s[i+1]=="W" and s[i+7]=="W" and s[i+8]=="W":
    print(moji[i])
    exit()
for i in range(13):
  if s[i]=="W" and s[i+1]=="W" and s[i+5]=="W" and s[i+6]=="W":
    print(moji2[i])
    exit()