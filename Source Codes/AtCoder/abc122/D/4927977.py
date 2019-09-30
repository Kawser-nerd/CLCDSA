#4
N=int(input())
memo = [{} for i in range(N)]

def check(last3,way,add,num):
    if num == 1:
        memo[num][last3+add] = way
    if num == 2:
        new_last3 = last3[-2:]+add
        if (new_last3!="AGC")&(new_last3!="GAC")&(new_last3!="ACG"):
            if new_last3 in memo[num]:
                memo[num][new_last3]+=way
            else:
                memo[num][new_last3]=way
    if num > 2:
        new_last3 = last3[-2:]+add
        new_last4 = last3[-3:]+add
        if (new_last3!="AGC")&(new_last3!="GAC")&(new_last3!="ACG"):
            if (new_last4!="AGAC")&(new_last4!="AGGC")&(new_last4!="AGTC")&(new_last4!="ATGC"):     
                if new_last3 in memo[num]:
                    memo[num][new_last3]+=way
                else:
                    memo[num][new_last3]=way

for c in "ATGC":
    memo[0][c] = 1

for i in range(1,N):
    for cj in memo[i-1]:
        last3 = cj
        way = memo[i-1][cj]
        for new_c in "ATCG":
            check(last3,way,new_c,i)
su = 0
for i in memo[N-1]:
    su += memo[N-1][i]
print(su%(10**9+7))