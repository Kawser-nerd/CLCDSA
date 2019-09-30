S=input()

l=len(S)

if l%2==0:
    count=l//2
    a=S[l//2-1]
    for i in range(l//2):
        if S[l//2-1-i]==a and S[l//2+i]==a:
            count+=1
        else:
            break
    print(count)
else:
    count=l//2+1
    a=S[l//2]
    for i in range(l//2):
        if S[l//2-1-i]==a and S[l//2+1+i]==a:

            count+=1
        else:
            break
    print(count)