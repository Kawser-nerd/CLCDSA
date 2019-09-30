#!/usr/bin/env python3



def S(i,j,r):
  global A
  global B
  global TABLE

  key = (i,j,r);
  if(key in TABLE):
    return TABLE[key]

  if len(A) == i:
    if r == None or r[0] != 0:
      TABLE[key] = 0;
      return 0;
    (_,nr,tr) = r
    s = sum([ nu for (nu,ty) in B[j:] if ty == tr ])

    val = min(s,nr)
    TABLE[key] = val
    return val

  if len(B) == j:
    if r == None or r[0] != 1:
      TABLE[key] = 0;
      return 0
    (_,nr,tr) = r
    s = sum([ nu for (nu,ty) in A[i:] if ty == tr ])

    val = min(s,nr)
    TABLE[key] = val
    return val

  # I am now guaranteed to index A[i],B[j]

  (n1,t1) = A[i]
  (n2,t2) = B[j]

  ex1 = 0
  ex2 = 0

  if r != None:
    (t, nr,tr) = r
    if t == 0:
      if t1 == tr:
        n1 += nr
      else:
        (n1,t1) = (nr,tr) # make not for extending A
        ex1 = -1
    else: # t == 1:
      if t2 == tr:
        n2 += nr
      else:
        (n2,t2) = (nr,tr) # make not for extending B
        ex2 = -1

  """
    if t1 == t2:
      if n1 == n2:
        result = n1 + S(i+1,j+1,None);
        TABLE[key] = result
        return result
        elif n1 < n2:

          r = (1,n2-n1,t2);
          result = n1 + S(i+1,j+1,r);
          TABLE[key] = result
          return result

          else:
            r = (0,n1-n2,t1)
            result = n2 + S(i+1,j+1,r);
            TABLE[key] = result
            return result
  """
  if t1 == t2:
    c = min(n1,n2)
    n1 -= c
    n2 -= c
    assert n1 == 0 or n2 == 0

    if n1 > 0:
      r = (0,n1,t1)
    elif n2 > 0:
      r = (1,n2,t2)
    else:
      r = None

    result = c + S(i+1+ex1,j+1+ex2,r)
    TABLE[key] = result
    return result;

  # t1 != t2
  if r == None:
    result = max(S(i+1,j,None),S(i,j+1,None))
    TABLE[key] = result
    return result
  else:
    if t == 0:
      result = max(S(i,j,None),S(i,j+1,r))
      TABLE[key] = result
      return result
    else:
      assert t == 1
      result = max(S(i+1,j,r),S(i,j,None))
      TABLE[key] = result
      return result

if __name__ == "__main__":
    T = int(input());
    for c in range(T):
        (N,M) = [int(x) for x in input().strip().split()]
        As = [int(x) for x in input().strip().split()]
        Bs = [int(x) for x in input().strip().split()]

        assert 2*N == len(As)
        assert 2*M == len(Bs)

        A = [(As[2*x],As[2*x+1]) for x in range(N)]
        B = [(Bs[2*x],Bs[2*x+1]) for x in range(M)]
        TABLE = dict()

        R = S(0,0,None)
        print("Case #{}: {}".format(c+1,R))