N=int(input())
x = (1+2+3+4+5+6+7+8+9)**2 - N

for i in range(1,10):
  if x%i==0 and x//i<=9:
    print('{} x {}'.format(i, x//i))