import string
A=string.ascii_lowercase
S=input()
if S==A[::-1]:
    print(-1)
elif len(S)==26:
    i=-1
    while S[i-1]>S[i]:
        i-=1
    for j in range(-1,i-1,-1):
        if S[j]>S[i-1]:
            c=S[j]
            break
    print(S[:i-1]+c)
else:
    c=sorted(set(A)-set(S))[0]
    print(S+c)