def count_inversions(L):
  def helper(A,B):
    lA,lB = len(A),len(B)
    if lA == 0:
      return B,0
    elif lB == 0:
      return A,0
    
    A,c1 = helper(A[:lA//2],A[lA//2:])
    B,c2 = helper(B[:lB//2],B[lB//2:])
    cnt = c1+c2
    i = 0
    j = 0

    C = [None]*(lA+lB)
    while i < lA and j < lB:
      if A[i] > B[j]:
        cnt += lA-i
        C[i+j] = B[j]
        j += 1
      else:
        C[i+j] = A[i]
        i += 1

    if i < lA:
      C[i+j:] = A[i:]
    else:
      C[i+j:] = B[j:]

    return C,cnt

  return helper(L[:len(L)//2],L[len(L)//2:])[1]

from collections import deque

ALPHABETS = 26

indices = [deque() for _ in range(26)]
S = list(map(lambda c: ord(c)-ord('a'),input()))
for i,c in enumerate(S):
  indices[c] += [i]

odd = None
for c,l in enumerate(indices):
  if len(l)%2 == 1:
    if odd is None:
      odd = c
    else:
      odd = -1
      break

if odd == -1:
  print(-1)
  exit()

target = [None]*len(S)
assigned = [False]*len(S)
if odd is not None:
  l = list(indices[odd])
  i = l[len(l)//2]
  target[len(target)//2] = i
  assigned[i] = True
  l = deque(l[:len(l)//2] + l[len(l)//2+1:])

j = 0
for i in range(len(S)//2):
  while assigned[j]:
    j += 1

  l = indices[S[j]]
  a = l.popleft()
  b = l.pop()
  assert a == j
  target[i] = a
  target[len(S)-i-1] = b
  assigned[a] = True
  assigned[b] = True
  
print(count_inversions(target))