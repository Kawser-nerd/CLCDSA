N=int(input())
S=input()

bool_list = [[True,True],[True,False],[False,True],[False,False]]

flag=False
for boo in bool_list:
    ans_list = list(boo)
    for i in range(1,N):

        if S[i]=="o":
            if ans_list[i]:
                if ans_list[i-1]:
                    ans_list.append(True)
                else:
                    ans_list.append(False)
            else:
                if ans_list[i-1]:
                    ans_list.append(False)
                else:
                    ans_list.append(True)
        else:
            if not ans_list[i]:
                if ans_list[i-1]:
                    ans_list.append(True)
                else:
                    ans_list.append(False)
            else:
                if ans_list[i-1]:
                    ans_list.append(False)
                else:
                    ans_list.append(True)
    
    if S[0]=="o":
        if ans_list[0]:
            if ans_list[1]:
                N_cand=True
            else:
                N_cand=False
        else:
            if ans_list[1]:
                N_cand=False
            else:
                N_cand=True
    else:
        if not ans_list[0]:
            if ans_list[1]:
                N_cand=True
            else:
                N_cand=False
        else:
            if ans_list[1]:
                N_cand=False
            else:
                N_cand=True
    
    if ans_list[0]==ans_list[N] and N_cand==ans_list[N-1]:
        flag=True
        break

if flag:
    ans=""
    for a in ans_list[:-1]:
        if a:
            ans+="S"
        else:
            ans+="W"
    print(ans)
else:
    print(-1)