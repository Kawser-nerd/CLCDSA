S=set(input())
print('Yes'if S in [{'N','S'},{'E','W'}]or len(S)%4==0 else'No')