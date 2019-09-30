def dfs(s,plus,i):

    i += 1

    if i == 4:
        ans = int(s[0])
        for j in range(1,4):
            ans += int(s[j])*plus[j-1]
        if ans == 7:
            ret = s[0]
            for k in range(1,4):
                if plus[k-1] == 1:
                    ret += '+'
                else:
                    ret += '-'
                ret += s[k]
            ret += '=7'
            print(ret)
            exit()
        return

    plus[i-1] = 1
    dfs(s, plus, i)

    plus[i-1] = -1
    dfs(s, plus, i)

    return


dfs(input(), [0,0,0], 0)