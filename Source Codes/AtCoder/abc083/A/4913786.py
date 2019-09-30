W = list(map(int, input().split()))
if (sum(W[:2:]) > sum(W[2::])):
  print('Left')
elif (sum(W[:2:]) < sum(W[2::])):
  print('Right')
else:
  print('Balanced')