S=input()
new_S=str()
for ii in list(S):
    if ii=='B':
        new_S=new_S[:-1]
    else:
        new_S+=ii
        
print(new_S)