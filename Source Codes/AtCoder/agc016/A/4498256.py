import copy
S=list(input())

ans=1000

A=["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
Li=[]
li=[]
for i in range(26):
    li=copy.deepcopy(S)
    if li.count(A[i])==len(li):
        print(0)
        exit()
    else:
        Li=copy.deepcopy(li)
        li=[]
        for k in range(len(S)):
            for j in range(len(Li)-1):
                if Li[j]==A[i] or Li[j+1]==A[i]:
                    li.append(A[i])
                else:
                    li.append("1")
            #print(li)
            if li.count(A[i])==len(li):
                if ans>len(S)-len(li):
                    ans=len(S)-len(li)
                break
            else:
                Li=copy.deepcopy(li)
                li=[]
print(ans)