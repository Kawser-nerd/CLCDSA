s = input()
s_list = list(s)
minis = []
for k in set(s):
  a = [i for i, x in enumerate(s_list) if x == k]
  mini = max(a[0], 0)
  for m in range(len(a) - 1):
    mini = max(a[m+1] - a[m] - 1, mini)
  mini = max(len(s) - a[-1] - 1, mini)
  minis.append(mini)
print(min(minis))