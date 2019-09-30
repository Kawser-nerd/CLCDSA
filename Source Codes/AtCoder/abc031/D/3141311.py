def dfs(i, f):
    global K, N, vw, num
    if i < 10:
        if not f:
            num[i] = 1
            f = dfs(i+1, f)
        if not f:
            num[i] = 2
            f = dfs(i+1, f)
        if not f:
            num[i] = 3
            f = dfs(i+1, f)
        return f
    else:
        ans = ["" for _ in range(10)]
        for j in range(N):
            s = vw[j][1]
            for k in range(len(vw[j][0])):
                if len(s) < num[int(vw[j][0][k])]:
                    return False
                if ans[int(vw[j][0][k])] == "":
                    ans[int(vw[j][0][k])] = s[:num[int(vw[j][0][k])]]
                    s = s[num[int(vw[j][0][k])]:]
                else:
                    if ans[int(vw[j][0][k])] != s[:num[int(vw[j][0][k])]]:
                        return False
                    s = s[num[int(vw[j][0][k])]:]
            if s != "":
                return False
        for j in range(1, K+1):
            print(ans[j])
        return True


K, N = map(int, input().split())
vw = [input().split() for _ in range(N)]
num = [0 for _ in range(10)]
dfs(1, False)