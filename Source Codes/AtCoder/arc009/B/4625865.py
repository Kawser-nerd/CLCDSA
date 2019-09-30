sbef = list("0123456789")
d = str.maketrans(input().replace(" ",""), "0123456789")
def tr(n):
  global d
  return(int(n.translate(d)))
n = int(input())
a = [input() for _ in range(n)]
a.sort(key=tr)
for i in a:
  print(i)