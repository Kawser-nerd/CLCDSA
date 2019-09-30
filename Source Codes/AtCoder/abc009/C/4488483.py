n,k = map(int,input().split())

s = input()

dic1 = {}

for i in s:
    if i in dic1:
        dic1[i] += 1
    else:
        dic1[i] = 1

def judge(i,j):
    cnt2 = cnt
    dic2 = dic.copy()
    if(j == s[i]):cnt2 += 1
    dic2[j] -= 1
    dic3 = dic1.copy()
    for kk in s[:i+1]:
        dic3[kk] -= 1
    cnt3 = 0
    for key in list(dic3):
        cnt3 += min(dic3[key],dic2[key])
    if(n-cnt3-cnt2 <= k  ): return True
    else : return False

l = sorted(list(dic1))
ans = ""
cnt = 0
dic = dic1.copy()
for i in range(len(s)):
    for j in l:
        if dic[j] == 0: 
            continue
        if judge(i,j):
            ans = ans + j
            dic[j] -= 1
            if(j == s[i]):cnt += 1
            break

print(ans)