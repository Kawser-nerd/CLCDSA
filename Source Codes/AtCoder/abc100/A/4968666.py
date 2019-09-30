i = list(map(int, input().split()))
A = i[0]
B = i[1]

if(A - B > 1 or B - A > 1):
  print(':(')

if((A - B) == 0 or (A - B) == 1 or (B - A) == 0 or (B - A) == 1):
  print('Yay!')