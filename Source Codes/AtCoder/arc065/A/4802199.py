S = input() 

S = S.replace('eraser','') 
S = S.replace('erase','')
S = S.replace('dreamer','')
S = S.replace('dream','')

if S == "":
    print("YES")
else:
    print("NO")