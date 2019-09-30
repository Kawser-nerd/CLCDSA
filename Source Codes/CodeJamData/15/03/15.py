TAB = {}
TAB[("1","1")]="1"
TAB[("1","i")]="i"
TAB[("1","j")]="j"
TAB[("1","k")]="k"
TAB[("i","1")]="i"
TAB[("i","i")]="-1"
TAB[("i","j")]="k"
TAB[("i","k")]="-j"
TAB[("j","1")]="j"
TAB[("j","i")]="-k"
TAB[("j","j")]="-1"
TAB[("j","k")]="i"
TAB[("k","1")]="k"
TAB[("k","i")]="j"
TAB[("k","j")]="-i"
TAB[("k","k")]="-1"
for ((a,b),x) in TAB.items():
  TAB[("-"+a,b)]=("-"+x).replace("--","")
  TAB[(a,"-"+b)]=("-"+x).replace("--","")
  TAB[("-"+a,"-"+b)]=x

def simplify(part):
  lst = list(part)
  while len(lst)>1:
    r = lst.pop()
    l = lst.pop()
    s = TAB[(l,r)]
    lst.append(s)
  return "".join(lst)

def solve(word, X):
  if X>12:
    X = 12+X%4
  word = list((word*X)[::-1])
  current = word.pop()
  while word and current!="i":
    current = TAB[(current,word.pop())]
  if word:
    current = word.pop()
  while word and current!="j":
    current = TAB[(current,word.pop())]
  word = "".join(word[::-1])
  return simplify(word)=="k"


T = input()

for t in range(1,T+1):
  (l,X) = map(int,raw_input().split(' '))
  word = raw_input()
  s = solve(word,X)
  yesno = "YES" if s else "NO"
  print "Case #%d: %s" % (t,yesno)
