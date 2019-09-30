A,B,C,D = map(int,input().split())
S,T = map(int,input().split())
if S+T>=D:
      print(A*S+B*T-C*(S+T))
else:
      print(A*S+B*T)