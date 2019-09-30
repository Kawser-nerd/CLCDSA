from itertools import chain,repeat
K,N = map(int,input().split())

def solve():

  if K % 2 == 0:
    return ' '.join(map(str, chain((K//2,),repeat(K,N-1))))
  else:
    seq = [K//2+1]*N
    d = N//2
    for _ in range(d):
      if seq[-1] == 1:
        seq.pop()
      else:
        seq[-1] -= 1
        seq.extend(repeat(K,N-len(seq)))
    return ' '.join(map(str, seq))

def naive():
  from itertools import product
  s = sorted(chain.from_iterable(product(range(1,K+1),repeat=i) for i in range(1,N+1)))
  return ' '.join(map(str, s[(len(s)-1)//2]))

print(solve())
# print(naive())