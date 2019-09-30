N, K = list(map(int, input().split()))
S = input()
alpha2num = {'a':0, 'b':1, 'c':2, 'd':3, 'e':4, 'f':5, 'g':6,
         'h':7, 'i':8, 'j':9, 'k':10, 'l':11, 'm':12,
         'n':13, 'o':14, 'p':15, 'q':16, 'r':17, 's':18,
         't':19, 'u':20, 'v':21, 'w':22, 'x':23, 'y':24, 'z':25,}
num2alpha = "abcdefghijklmnopqrstuvwxyz"  
  
numS = []
for i in range(N):
  numS.append(alpha2num[S[i]])
  
sortednumS = sorted(numS)

def tradable(origin, target, K):
  for i in range(len(origin)):
    if origin[i] in target:  
        target.remove(origin[i])
    else:
        K -= 1
  return K >= 0

smallest = []
#?????????
for i in range(N):
  #i?????????
  for idx in range(len(sortednumS)):
    si = sortednumS[idx]
    left = sortednumS[:idx] + sortednumS[idx+1:]
    if si == numS[i]:
      istradable = tradable(left, numS[i+1:], K)
      if istradable:
        break
    else:
      istradable = tradable(left, numS[i+1:], K-1)
      if istradable:
        K -= 1
        break
  sortednumS.remove(si)
  smallest.append(si)
  
result = ""
for i in range(N):
  result += num2alpha[smallest[i]]
print(result)