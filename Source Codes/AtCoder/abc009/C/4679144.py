N,K=map(int, input().split())
S=str(input())
base=list(S)
base.sort()
tmp=""
tmp2=""
tmp_base=[]
mismatch1=0
mismatch2=0
counter=0
result=""
tmp_result=""
tmp_S=""
t=0
rest=[]
tmp_ans="a"
for i in range(0,N-1):
    #i+1??????
    for cha in base:
        mismatch2=0
        tmp_base=[]
        tmp_base+=base
        if(cha!=S[i]):
            mismatch2+=1
        #?????
        tmp_base.remove(cha)
        for j in range(i+1,N):
            if(S[j] in tmp_base):
                tmp_base.remove(S[j])
            else:
                mismatch2+=1
        if(mismatch1+mismatch2<=K):
            tmp_ans=cha
            break
    result+=tmp_ans
    base.remove(tmp_ans)
    if(tmp_ans!=S[i]):
        mismatch1+=1

result+=base[0]
print(result)