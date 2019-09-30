A,B,K=map(int,input().split())
if B-A < K :
  for i in range(A,B+1) :
    if i < A+K or B-K < i :
      print(i)
else :
  S=set()
  for i in range(K) :
    S.add(A+i)
    S.add(B-i)
  L=list(S)
  L.sort() 
  for i in L :
    print(i)