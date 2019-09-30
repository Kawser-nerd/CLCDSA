s = input()
t = input()
ls = len(s)
lt = len(t)
sl = [0]*(ls+1)
tl = [0]*(lt+1)
for i in range(ls):
  if s[i] == "A":
    sl[i+1] = sl[i] + 1
  else:
    sl[i+1] = sl[i] + 2
for i in range(lt):
  if t[i] == "A":
    tl[i+1] = tl[i] + 1
  else:
    tl[i+1] = tl[i] + 2
for _ in range(int(input())):
  a,b,c,d = map(int, input().split())
  if (sl[b]-tl[d]-sl[a-1]+tl[c-1])%3 == 0:
    print("YES")
  else:
    print("NO")