N = int(input())
D, E = [0, 1]
for i in range(2, N + 1):
  print('? 1 {}'.format(i), flush=True)
  d = int(input())
  if d > D:
    D, E = [d, i]
for i in range(1, N + 1):
  if i != E:
    print('? {} {}'.format(E, i), flush=True)
    D = max(int(input()), D)
print('! {}'.format(D))