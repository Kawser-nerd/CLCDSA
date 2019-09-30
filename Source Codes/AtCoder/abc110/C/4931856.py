# -*- coding:utf-8 -*-

def calc(S, T):
    # ??????
    ans = 0
    for i in range(len(S)):
        if S[i] != T[i]:
            ans += 1
    return ans


def solve():
    s = input()
    S = [moji for moji in s]
    T = input()

    # ????????????????????????
    
    diff = calc(S, T)
    if diff == 0:
        print("Yes")
        return
    pre_diff = diff

    while True:
        # c1, c2????
        for i in range(len(S)):
            if S[i] != T[i]:
                c1 = S[i]
                c2 = T[i]
                break
        
        # ????????
        for i in range(len(S)):
            if S[i] == c1:
                S[i] = c2
            elif S[i] == c2:
                S[i] = c1
        
        # ??????
        diff = calc(S, T)
        if diff == 0:
            break
        elif diff < pre_diff:
            pre_diff = diff
            continue
        else:
            print("No")
            return
    print("Yes")





if __name__ == "__main__":
    solve()