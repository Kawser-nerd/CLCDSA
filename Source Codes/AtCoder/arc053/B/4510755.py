S=input()
A=["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]

odd=0
for i in range(26):
    if S.count(A[i])%2==1:
        odd+=1
#print(odd)
if odd==0:
    print(len(S))
else:
    for i in range(1000000):
        if len(S)<(1+2*i)*odd:
            break
    
    print(1+2*(i-1))