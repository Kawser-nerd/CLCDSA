n = int(input())
ls = []
for i in range(n):
  tmp = int(input())
  if tmp not in ls:
    ls.append(tmp)

ls = sorted(ls)
ls.pop(len(ls)-1)
print(max(ls))