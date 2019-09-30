#coding=UTF-8

N=int(input())
S=input()

slot=''
for idx in range(0,len(S),1):
#    print(slot)
    if len(slot)==0:
        slot=S[idx]
    elif len(slot)==1:
        slot=slot+S[idx]
        if slot[0]==slot[1]:
            slot=''
    else:
        if S[idx]==slot[0]:
            slot=slot[1:len(slot)]
        elif S[idx]==slot[-1]:
            slot=slot[0:len(slot)-1]
        else:
            #???????? ???
            if idx == len(S)-1:
                slot=slot+S[idx]
            else:
                if S[idx+1]==slot[0]:
                    slot=slot+S[idx]
                else:
                    slot=S[idx]+slot

print(len(slot))