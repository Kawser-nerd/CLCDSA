N, S, T = map(int, input().split())
W = int(input())
if  S <= W <= T:
  daycount = 1
else:
  daycount = 0
for i in range(N - 1):
  A = int(input())
  W += A
  if S <= W <= T:
    daycount += 1
print(daycount)