A = input()
lenA = len(A)
A1 = A[:lenA//2]
A2 = A[lenA-lenA//2:][::-1]

if A1 == A2:
    if lenA%2==0:
        print(25*lenA)
        exit()
    else:
        print(25 * lenA-25)
        exit()

count=0
for i,z in zip(A1,A2):
    if i !=z:
        count+=1
if count==1:
    print((lenA-2)*25+24*2)
else:
    print(lenA*25)