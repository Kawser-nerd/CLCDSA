s=input()

gu=0
pa=0
win=0

for t in s:
  if t=='g':
    if gu>pa:
      pa+=1
      win+=1
    else:
      gu+=1
  else:
    if gu>pa:
      pa+=1
    else:
      win-=1
      gu+=1
print(win)