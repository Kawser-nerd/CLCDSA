n = int(input())
l = []
for i in range(n):
  l.append(int(input()))
print(sum(l))
l.sort(reverse=True)
min_no = l[0]
for x in range(1,len(l)):
  min_no -= l[x]
if min_no <= 0:
  min_no =0
print(min_no)