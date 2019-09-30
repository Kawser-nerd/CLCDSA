arr={'A':0, 'B':1, 'C':2, 'D':3, 'E':4, 'F':5}
x,y=map(str,input().split())
if arr[x]>arr[y]:
  print('>')
elif arr[x]<arr[y]:
  print('<')
else:
  print('=')