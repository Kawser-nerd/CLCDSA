# ARC 063
S = input()
count = 0
stn = S[0]
i = 1
while i<len(S):
    while i<len(S) and stn==S[i] : i+=1 # ???????
    if i<len(S): 
        count += 1
        stn = S[i]
print(count)