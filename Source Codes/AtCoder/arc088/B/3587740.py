S=input()
prev=S[0]
T=len(S)
for i in range(1, len(S)):
    if S[i]!=prev:
        T=min(T,max(i,len(S)-i))
        prev=S[i]
print(T)