I,O,T,J,L,S,Z = map(int,input().split())
print(max(((I-1)//2+(J-1)//2+(L-1)//2)*2+O+3*(I>0)*(L>0)*(J>0),(I//2+J//2+L//2)*2+O))