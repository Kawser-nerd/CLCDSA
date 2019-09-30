def assign(s,ans,n):
    for i in range(1,n-1):
        if s[i] == "o":
            if ans[i] == "S":
                if ans[i-1] == "S":
                    ans[i+1] = "S"
                else:
                    ans[i+1] = "W"
            else:
                if ans[i-1] == "S":
                    ans[i+1] = "W"
                else:
                    ans[i+1] = "S"
        else:
            if ans[i] == "S":
                if ans[i-1] == "S":
                    ans[i+1] = "W"
                else:
                    ans[i+1] = "S"
            else:
                if ans[i-1] == "W":
                    ans[i+1] = "W"
                else:
                    ans[i+1] = "S"
    return ans

def judge(s,ans):
    check = True
    if s[0] == "o":
        if ans[0] == "S":
            if ans[1] != ans[-1]:
                check = False
        else:
            if ans[1] == ans[-1]:
                check = False
    else:
        if ans[0] == "S":
            if ans[1] == ans[-1]:
                check = False
        else:
            if ans[1] != ans[-1]:
                check = False

    if s[-1] == "o":
        if ans[-1] == "S":
            if ans[-2] != ans[0]:
                check = False
        else:
            if ans[-2] == ans[0]:
                check = False
    else:
        if ans[-1] == "S":
            if ans[-2] == ans[0]:
                check = False
        else:
            if ans[-2] != ans[0]:
                check = False
    return check


n = int(input())
s = list(input())
whole = False
for i in range(4):
    ans = [1 for i in range(n)]
    if i == 0:
        ans[0] = "S"
        ans[1] = "S"
    elif i == 1:
        ans[0] = "S"
        ans[1] = "W"
    elif i == 2:
        ans[0] = "W"
        ans[1] = "S"
    elif i == 3:
        ans[0] = "W"
        ans[1] = "W"
    ans = assign(s,ans,n)
    check = judge(s,ans)
    if check:
        for i in range(n):
            if i != n-1:
                print(ans[i],end = "")
            else:
                print(ans[i])
        whole = True
        break
if whole == False:
    print("-1")