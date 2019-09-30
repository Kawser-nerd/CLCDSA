# coding: utf8

if __name__ == '__main_sample__':
    """
        (A, B)?(A+1, B+1)?????????.
        (0, 0), (0, 1) ... (0, N-1)????????????.
    """
    N = int(input())
    rows = [input() for _ in range(N)]
    ans = 0
    for n in range(N):
        flag = False
        for i in range(N):
            for j in range(N):
                num = j - n if j - n >= 0 else N + (j - n)
                a = i - n if i - n >= 0 else N + (i - n)
                if rows[i][num] != rows[j][a]:
                    flag = True
                    break
            if flag == True:
                break
        if flag == False:
            ans += 1
    print(ans * N)

if __name__ == '__main__':
    """
        ????????
    """
    N = int(input())
    Sss = [input() for _ in range(N)]
    Sss_tr = list(map(''.join, zip(*Sss))) # ??
    ans = 0
    for k in range(N):
        for i in range(N):
            if (Sss[i][-k:] + Sss[i][:-k]) != Sss_tr[i - k]:
                break
        else:
            ans += N
    
    print(ans)