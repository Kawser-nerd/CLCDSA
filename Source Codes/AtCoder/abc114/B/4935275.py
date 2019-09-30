S=[int(i) for i in input()]
ans=0
for i in range(len(S)-2):
    dog_cup=100*S[i]+10*S[i+1]+S[i+2]
    if abs(753-ans)>abs(753-dog_cup):
        ans=dog_cup
print(abs(753-ans))