N = int(input())
SUM = 2025

diff = SUM - N
for i in range(9):
  if diff % (i + 1) == 0 and diff // (i + 1) <= 9:
    print("{0} x {1}".format(i + 1, diff // (i + 1)))