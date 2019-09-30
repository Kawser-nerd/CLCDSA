a,b,c,d=map(int,input().split())
ta=b/a
ao=d/c
if ta>ao:
  print('TAKAHASHI')
elif ao>ta:
  print('AOKI')
else:
  print('DRAW')