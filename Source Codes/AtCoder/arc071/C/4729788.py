S = input()
T = input()

q = int(input())

SA = [0]
SB = [0]
TA = [0]
TB = [0]

sa=0
sb=0
ta=0
tb=0

for i in range(len(S)):
    if S[i]=="A":
        sa+=1
    elif S[i]=="B":
        sb+=1
    SA.append(sa)
    SB.append(sb)
    

for i in range(len(T)):
    if T[i]=="A":
        ta+=1
    elif T[i]=="B":
        tb+=1
    TA.append(ta)
    TB.append(tb)

for i in range(q):
    a,b,c,d = list(map(int,input().split()))
    sa_num=SA[b]-SA[a-1]
    sb_num=SB[b]-SB[a-1]
    ta_num=TA[d]-TA[c-1]
    tb_num=TB[d]-TB[c-1]
    if (sa_num+2*sb_num)%3==(ta_num+2*tb_num)%3:
        print("YES")
    else:
        print("NO")