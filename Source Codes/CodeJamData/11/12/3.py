#!/usr/bin/python

from collections import *

def inwords(x, l):
    for y in l:
        if x in y[0]:
            return True
    return False

def fillin(wordstr, tem, letter):
    ntem=""
    for t in range(len(wordstr)):
        if wordstr[t]==letter:
            ntem=ntem+wordstr[t]
        else:
            ntem=ntem+tem[t]
    #print(str(("fillin ",tem,wordstr,letter,ntem)))
    return ntem
    
def work(words, gseq):
    #print(words)
    l=len(words[0][0])
    tem0="_"*l
    #print(tem0)
    q=deque()
    q.append((tem0,words,0))
    while len(q)>0:
        tem, ws, gi=q.popleft()
        if len(ws)>1:
            #xxx
            #print("POP "+str((tem,ws,gi)))
            while not inwords(gseq[gi], ws):
                gi=gi+1
            d=dict()
            for w in ws:
                ntem=fillin(w[0], tem, gseq[gi])
                if ntem==tem:
                    #print("XXXXX")
                    w[1]=w[1]+1
                if ntem not in d:
                    d[ntem]=[]
                d[ntem].append(w)
            di=d.items()
            for i in di:
                #print("PUSH "+str((i[0],i[1],gi+1)))
                q.append((i[0],i[1],gi+1))
        
    #for w in words:
    #    w[1]=len(w[0])/2
    
    #print(words)


def workall(allwords, gseq):
    wordsbylen=[[] for i in range(20)]
    for w in allwords:
        l=len(w[0])
        wordsbylen[l].append(w)
    #print(wordsbylen)
    for words in wordsbylen:
        if len(words)>0:
            work(words,gseq)
    #print(wordsbylen)
    return None


T=int(input())
for tt in range(1,T+1):
    line=input().split()
    n=int(line[0])
    M=int(line[1])
    words=[]
    for i in range(0,n):
        w=[input(),0]
        words.append(w)
    res="Case #%d:" % tt
    
    for dixie in range(0,M):
        if dixie>0:
            for w in words:
                w[1]=0
        gseq=input()
        #print(gseq)
        workall(words, gseq)
        #print(words)
        ans,ansmax="",-1
        for w in words:
            if w[1]>ansmax:
                ans,ansmax=w
        res=res+" "+ans
        
    print(res)
