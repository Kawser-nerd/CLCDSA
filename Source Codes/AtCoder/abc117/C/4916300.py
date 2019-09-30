N, M = map(int, input().split(" "))
Xs = map(int, input().split(" "))

X_lst = sorted(Xs)
dX = sorted([X_lst[i+1] - X_lst[i] for i in range(len(X_lst)-1)])
if N >= M:
  print(0)
elif N == 1:
  print(sum(dX))
else:
  print(sum(dX[:-(N-1)]))