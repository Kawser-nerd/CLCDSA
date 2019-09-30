abc="abcdefghijklmnopqrstuvwxyz"

A=str(input())
n=len(A)
#make matrix (a-z)*(n characters)
#??chr?????index
word_pos=[]
ct=[n]*26
orda=ord("a")

for i in range(n-1,-1,-1):
    ct[ord(A[i])-orda]=i
    word_pos.append(ct.copy())

word_pos.reverse()

dp=[0]*n+[1,0]
j=n
sep=[]
#????????
for i in range(n-1,-1,-1):
    ct=word_pos[i]
    if(max(ct)<j):
        #remove last chunk
        sep.append(i)
        j=min(ct)
        
if(j==n):
    for i in abc:
        if(i not in A):
            print(i+"\n")
            break

else:
    sep.reverse()
    ans=""
    for i in abc:
        if(i not in A[:sep[0]]):
            ans+=i
            break

    for i in range(0,len(sep)):
        start=sep[i]
        try:
            end=sep[i+1]
        except:
            end=n
        #ans[-1]??????????
        next=word_pos[start][ord(ans[-1])-orda]
        for i in range(0,26):
            if(word_pos[next+1][i]>end-1):
                ans+=chr(orda+i)
                break
    ans+="\n"
    print(ans)