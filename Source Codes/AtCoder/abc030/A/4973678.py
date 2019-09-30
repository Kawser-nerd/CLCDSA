a,b,c,d = map(int,input().split())

takahashi = b/a
aoki = d/c

if aoki > takahashi:
  print('AOKI')
elif aoki < takahashi:
  print('TAKAHASHI')
else:
  print('DRAW')