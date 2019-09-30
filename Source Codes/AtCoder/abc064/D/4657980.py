n = int(input())
s = input()
que = []
for i in range(n):
  if s[i] == ")" and que and que[-1] == "(":
    que.pop()
  else:
    que.append(s[i])
ket = que.count(")")
bra = len(que) - ket
print("("*ket + s + ")"*bra)