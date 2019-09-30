A, B = map(int, input().split())
S = input()
falg = False

if S.count('-') == 1: 
  code_1, code_2 = S.split('-')
  if (len(code_1) == A) and (len(code_2) == B):
    flag = True
  else:
    flag = False

  if (code_1+code_2).isdecimal() and flag:
    flag = True
  else:
    flag = False

else:
  flag = False
        
if flag:
  print('Yes')
else:
  print('No')