I,O,T,J,L,S,Z=map(int,input().split())
A=((I-1)//2)*2+O+((J-1)//2)*2+((L-1)//2)*2+3
B=(I//2)*2+O+(J//2)*2+(L//2)*2
if I==0 or J==0 or L==0:
  print(B)
else:
  print(max(A,B))