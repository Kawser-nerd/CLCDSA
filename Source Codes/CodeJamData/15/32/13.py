
def findLongestPrefix(st):
  ret = 0
  for i in range(len(st)-1):
#    print st[:(i+1)]
#    print st[(len(st)-(i+1)):]
#    print("----")
    if(st[:(i+1)] == st[(len(st)-(i+1)):]):
      ret = max(ret,i+1)
  return ret

def maxRepeating(st,targetLen):
  pe = findLongestPrefix(st)
  d = len(st) - pe
  return 1 + (targetLen-len(st)) / d
  
K = 0
L = 0
S = 0
keyb = ""
targ = ""
vysk = {}

def prob(targ, keyb, K):
  vysk = {}
  for i in range(len(keyb)):
    vysk[keyb[i]]=0
  for i in range(len(keyb)):
    vysk[keyb[i]] = vysk[keyb[i]]+1 
  ret = 1
  for i in range(len(targ)):
    x = 0
    if(targ[i] in vysk):
      x = vysk[targ[i]]
    ret = ret * float(x) / float(K)
  return ret

def solve():
  row = raw_input().split()
  K = int(row[0])
  L = int(row[1])
  S = int(row[2])
#  print(K)
#  print(L)  
#  print(S)  
  keyb = raw_input()
#  print keyb
  targ = raw_input()
  vysk = {}
  for i in range(len(keyb)):
    vysk[keyb[i]]=0
  for i in range(len(targ)):
    if(targ[i] not in vysk):
      return "0.0"

#  print targ
#  print(findLongestPrefix("abxxab"))
  worst = maxRepeating(targ, S)
  w = prob(targ, keyb, K) * (S-L+1)
  #print worst - w
  ret = worst - w
  rets = "{0:.15f}".format(ret)
  return rets

TTT = int(input())
for ttt in range(1,TTT+1):
  
  print('Case #{}: {}'.format(ttt,solve()))
